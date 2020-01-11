#pragma once

#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>
#include "Figure.h"
#include "Level.h"

using namespace std;

class BaseApp
{
private:
	HANDLE mConsole;
	HANDLE mConsoleIn;

	CHAR_INFO* mChiBuffer;
	COORD mDwBufferSize;
	COORD mDwBufferCoord;
	SMALL_RECT mLpWriteRegion;

	void Render();

public:
	//размеры области вывода по горизонтали и вертикали в символах
	const int X_SIZE;
	const int Y_SIZE;

	string textConsol;

	//создаем экземпл€р класса level
	Level level;

	//аргументами €вл€ютс€ размеры области вывода по горизонтали и вертикали в символах
	BaseApp(int xSize=20, int ySize=30);
	virtual ~BaseApp();

	//запускает игровой цикл
	void Run();
	void RenderMenu();

	void RunGame();
	//можно заполнить x,y-символ экрана определенным символом, или считать его
	void SetChar(int x, int y, int color, wchar_t c);
	wchar_t GetChar(int x, int y);

	
	void setTextConsol(int x, int y, int color, string text);
	void setCountPointConsol(int x, int y, int point);
	void setHeartLevel(int x, int y, int heartsLevel);
	void setTimerEnergizerConsol(int x, int y, int timerEnergizer);

	/*эта функци€ вызываетс€ каждую игровую итерацию, еЄ можно переопределить, в наследнике класса.
	в неЄ приходит deltaTime - разница во времени между предыдущей итерацией и этой, в секундах*/
	virtual void UpdateF (float deltaTime){}
	/*эта функци€ вызываетс€ при нажатии клавиши на клавиатуре, в неЄ приходит код клавиши - btnCode.
	если использовать стрелки или функциональные клавиши, то придет общее дл€ них число, например 224, а следующее за ним - 
	будет уже непосредственно код самой клавиши, его можно получить, вызвав метод getch().
	ћетод KeyPressed так же можно переопределить в наследнике*/
	virtual void KeyPressed (int btnCode){}
};