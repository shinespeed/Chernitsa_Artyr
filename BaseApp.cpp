#include "stdafx.h"
#include <algorithm>
#include <time.h>
#include <conio.h>
#include <assert.h>
#include <strsafe.h>
#include "Game.h"

#define MY_PERFORMENCE_COUNTER

#include "PerformanceCounter.h"

BaseApp::BaseApp(int xSize, int ySize) : X_SIZE(xSize), Y_SIZE(ySize)
{
	SMALL_RECT windowSize = {0, 0, X_SIZE, Y_SIZE};
	COORD windowBufSize = {X_SIZE+1, Y_SIZE+1};

	mConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	mConsoleIn = GetStdHandle(STD_INPUT_HANDLE);

	if(!SetConsoleScreenBufferSize(mConsole,  windowBufSize))
	{
		cout << "SetConsoleScreenBufferSize failed with error " << GetLastError() << endl;
	}
	if(!SetConsoleWindowInfo(mConsole, TRUE, &windowSize))
	{
		cout << "SetConsoleWindowInfo failed with error " << GetLastError() << endl;
	}


	CONSOLE_CURSOR_INFO cursorInfo;
	GetConsoleCursorInfo(mConsole, &cursorInfo);
	cursorInfo.bVisible = FALSE;
	cursorInfo.dwSize = 1;
	SetConsoleCursorInfo(mConsole, &cursorInfo);


	mChiBuffer = (CHAR_INFO*)malloc((X_SIZE+1)*(Y_SIZE+1)*sizeof(CHAR_INFO));

	mDwBufferSize.X = X_SIZE + 1;
	mDwBufferSize.Y = Y_SIZE + 1;		// размер буфера данных

	mDwBufferCoord.X = 0;
	mDwBufferCoord.Y = 0;				// координаты ячейки

	mLpWriteRegion.Left = 0;
	mLpWriteRegion.Top = 0;
	mLpWriteRegion.Right = X_SIZE + 1;
	mLpWriteRegion.Bottom = Y_SIZE + 1;	// прямоугольник для чтения


	for (int x=0; x<X_SIZE+1; x++)
	{
		for (int y=0; y<Y_SIZE+1; y++)
		{
			SetChar(x, y, 1,L' ');
		}
	}
}

BaseApp::~BaseApp()
{
	free(mChiBuffer);
}

void BaseApp::SetChar(int x, int y, int color, wchar_t c)
{
	mChiBuffer[x + (X_SIZE+1)*y].Char.UnicodeChar = c;
	mChiBuffer[x + (X_SIZE+1)*y].Attributes = color;

}

wchar_t BaseApp::GetChar(int x, int y)
{
	return mChiBuffer[x + (X_SIZE+1)*y].Char.AsciiChar;
}

void BaseApp::setTextConsol(int x, int y, int color, string text)
{
	char buffer;
	int indx = 0;
	for (int i = 0; i < text.length(); i++) 
	{
		buffer = text[i];
		SetChar(x - (text.length()) + i, y, 7, buffer);
	}
}

void BaseApp::setHeartLevel(int x, int y, int heartLevel) 
{
	for (int i = 0; i < heartLevel; i++)
	{
		SetChar(x + i, y, 4, 3);
	}
}

void BaseApp::setCountPointConsol(int x, int y, int point)
{
	string str = to_string(point); 
	setTextConsol(x, y, 0,"00000");
	setTextConsol(x, y, 7,str);
}

void BaseApp::setTimerEnergizerConsol(int x, int y, int timerEnergizer) 
{
	string str = to_string(timerEnergizer);
	setTextConsol(x, y, 7, "00");
	setTextConsol(x, y, 7,str);
}
void BaseApp::RenderMenu() 
{
	if (!WriteConsoleOutput(mConsole, mChiBuffer, mDwBufferSize, mDwBufferCoord, &mLpWriteRegion))
	{
		printf("WriteConsoleOutput failed - (%d)\n", GetLastError());
	}
}

void BaseApp::Render()
{
	if (!WriteConsoleOutput(mConsole, mChiBuffer, mDwBufferSize, mDwBufferCoord, &mLpWriteRegion)) 
	{
		printf("WriteConsoleOutput failed - (%d)\n", GetLastError()); 
	}

	setHeartLevel(35, 2, level.heartLevel);
	setCountPointConsol(40,1,level.pointPlayer);

	for (int i = 0; i < 20; i++) 
	    {
		for (int j = 0; j < 30; j++) 
		   {
			if (level.arrayFigure[i][j] == nullptr)
			{
				SetChar(j, i, 0, L' ');
			}
			else switch (level.arrayFigure[i][j]->coordFigure()->typeFigure)
			{
			     case PACMAN: SetChar(j, i, 6, 2); break;
			     case WALL:	SetChar(j, i, 1, 10); break;
				 case COIN:	SetChar(j, i, 7, L'.'); break;
				 case ENERGIZER: SetChar(j, i, 4, 5); break;
			}
		}
	}
}

void BaseApp::RunGame()
{
	CStopwatch timer;
	int sum = 0;
	int counter = 0;

	int deltaTime = 0;

	while (1)
	{
		timer.Start();
		if (_kbhit())
		{
			KeyPressed(_getch());
			if (!FlushConsoleInputBuffer(mConsoleIn))
				cout << "FlushConsoleInputBuffer failed with error " << GetLastError();
		}

		UpdateF((float)deltaTime / 1000.0f);
		Render();
		Sleep(1);

		while (1)
		{
			deltaTime = timer.Now();
			if (deltaTime > 20)
				break;
		}

		sum += deltaTime;
		counter++;
		if (sum >= 1000)
		{
			TCHAR  szbuff[255];
			StringCchPrintf(szbuff, 255, TEXT("FPS: %d"), counter);
			SetConsoleTitle(szbuff);

			counter = 0;
			sum = 0;
		}
	}

}

void BaseApp::Run()
{
	RunGame();
}