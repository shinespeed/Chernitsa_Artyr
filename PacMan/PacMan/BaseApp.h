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

public:
	//������� ������� ������ �� ����������� � ��������� � ��������
	const int X_SIZE;
	const int Y_SIZE;

	string textConsol;

	//������� ��������� ������ level

	//����������� �������� ������� ������� ������ �� ����������� � ��������� � ��������
	BaseApp(int xSize=30, int ySize=20);
	virtual ~BaseApp();

	//��������� ������� ����
	void Run();

	//����� ��������� x,y-������ ������ ������������ ��������, ��� ������� ���
	void SetChar(int x, int y, int color, wchar_t c);
	wchar_t GetChar(int x, int y);

	void Render();
	void setTextConsol(int x, int y, int color, string text);
	void setCountPointConsol(int x, int y, int point);
	void setHealthLevel(int x, int y, int healthLevel);
	void setTimerEnergizerConsol(int x, int y, int timerEnergizer);
	void setLevelConsol(int x, int y, int level);

	/*��� ������� ���������� ������ ������� ��������, � ����� ��������������, � ���������� ������.
	� �� �������� deltaTime - ������� �� ������� ����� ���������� ��������� � ����, � ��������*/
	virtual bool Update (float deltaTime){return 0;}
	/*��� ������� ���������� ��� ������� ������� �� ����������, � �� �������� ��� ������� - btnCode.
	���� ������������ ������� ��� �������������� �������, �� ������ ����� ��� ��� �����, �������� 224, � ��������� �� ��� - 
	����� ��� ��������������� ��� ����� �������, ��� ����� ��������, ������ ����� getch().
	����� KeyPressed ��� �� ����� �������������� � ����������*/
	virtual void KeyPressed (int btnCode){}
};