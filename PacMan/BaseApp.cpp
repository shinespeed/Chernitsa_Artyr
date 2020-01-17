﻿#include <algorithm>
#include <time.h>
#include <conio.h>
#include <assert.h>
#include <strsafe.h>
#include "Game.h"
#include "BaseApp.h"
#include "PerformanceCounter.h"
#include "GlobalConst.h"

BaseApp::BaseApp(int xSize, int ySize) 
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

void BaseApp::setLevelConsol(int x, int y, int level) 
{
	setTextConsol(x, y, WHITE, "Level: " + to_string(level));
}

void BaseApp::setTextConsol(int x, int y, int color, string text)
{
	char buffer;
	int indx = 0;
	for (int i = 0; i < text.length(); i++) 
	{
		buffer = text[i];
		SetChar(x - (text.length()) + i, y, color, buffer);
	}
}

void BaseApp::setHealthLevelConsol(int x, int y, int healthLevel) 
{
	setTextConsol(x + 5, y, BLACK, "       ");
	for (int i = 0; i < healthLevel; i++)
	{
		SetChar(x + i, y, RED, SYMBOLHEARTH);
	}
}

void BaseApp::setCountPointConsol(int x, int y, int point)
{
	setTextConsol(x, y, WHITE, to_string(point));
}

void BaseApp::setTimerEnergizerConsol(int x, int y, int timerEnergizer) 
{
	setTextConsol(x, y, WHITE, "00");
	setTextConsol(x, y, WHITE, to_string(timerEnergizer));
}

void BaseApp::Render()
{
	if (!WriteConsoleOutput(mConsole, mChiBuffer, mDwBufferSize, mDwBufferCoord, &mLpWriteRegion)) 
	{
		printf("WriteConsoleOutput failed - (%d)\n", GetLastError()); 
	}
}

void BaseApp::Run()
{
	CStopwatch timer;
	int sum = 0;
	int counter = 0;
	int deltaTime = 0;

	while (Update(static_cast<float>(deltaTime) / 1000.0f))
	{
		timer.Start();
		if (_kbhit())
		{
			KeyPressed(_getch());
			if (!FlushConsoleInputBuffer(mConsoleIn))
				cout << "FlushConsoleInputBuffer failed with error " << GetLastError();
		}

		Render();
		Sleep(1);

		while (true)
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
			StringCchPrintf(szbuff, 255, TEXT("PacMan FPS: %d"), counter);
			SetConsoleTitle(szbuff);

			counter = 0;
			sum = 0;
		}
	}
}