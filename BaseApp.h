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
	//������� ������� ������ �� ����������� � ��������� � ��������
	const int X_SIZE;
	const int Y_SIZE;

	string textConsol;

	//������� ��������� ������ level
	Level level;

	//����������� �������� ������� ������� ������ �� ����������� � ��������� � ��������
	BaseApp(int xSize=20, int ySize=30);
	virtual ~BaseApp();

	//��������� ������� ����
	void Run();
	void RenderMenu();

	void RunGame();
	//����� ��������� x,y-������ ������ ������������ ��������, ��� ������� ���
	void SetChar(int x, int y, int color, wchar_t c);
	wchar_t GetChar(int x, int y);

	
	void setTextConsol(int x, int y, int color, string text);
	void setCountPointConsol(int x, int y, int point);
	void setHeartLevel(int x, int y, int heartsLevel);
	void setTimerEnergizerConsol(int x, int y, int timerEnergizer);

	/*��� ������� ���������� ������ ������� ��������, � ����� ��������������, � ���������� ������.
	� �� �������� deltaTime - ������� �� ������� ����� ���������� ��������� � ����, � ��������*/
	virtual void UpdateF (float deltaTime){}
	/*��� ������� ���������� ��� ������� ������� �� ����������, � �� �������� ��� ������� - btnCode.
	���� ������������ ������� ��� �������������� �������, �� ������ ����� ��� ��� �����, �������� 224, � ��������� �� ��� - 
	����� ��� ��������������� ��� ����� �������, ��� ����� ��������, ������ ����� getch().
	����� KeyPressed ��� �� ����� �������������� � ����������*/
	virtual void KeyPressed (int btnCode){}
};