#ifndef BASEAPP_H
#define BASEAPP_H

#include <iostream>
#include <Windows.h>
#include <vector>
#include <string>

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

public:
	BaseApp(int xSize = 40, int ySize = 20);
	virtual ~BaseApp();

	const int X_SIZE;
	const int Y_SIZE;

	string textConsol;

	void Run();

	void SetChar(int x, int y, int color, wchar_t c);
	wchar_t GetChar(int x, int y);

	void Render();
	void setTextConsol(int x, int y, int color, string text);
	void setCountPointConsol(int x, int y, int point);
	void setHealthLevel(int x, int y, int healthLevel);
	void setTimerEnergizerConsol(int x, int y, int timerEnergizer);
	void setLevelConsol(int x, int y, int level);

	virtual bool Update(float deltaTime) = 0;
	virtual void KeyPressed(int btnCode) = 0;
};

#endif