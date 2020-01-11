#include "stdafx.h"
#include "Game.h"

Game::Game(): Parent(100, 80)
{
	mDirection = true;
	tempFigureX = level.startPlayerX;
	tempFigureY = level.startPlayerY;
	addSumFigure = 0;
	sumTempTimer = 0;
	temp = nullptr;
}

void Game::KeyPressed(int btnCode)
{
	if ((btnCode == 119)&&(moveRegulFigure(tempFigureX, tempFigureY-1))) //w
		tempFigureY--;
	else if ((btnCode == 115)&&(moveRegulFigure(tempFigureX, tempFigureY + 1))) //s
		tempFigureY++;
	else if ((btnCode == 97)&&(moveRegulFigure(tempFigureX - 1, tempFigureY))) //a
		tempFigureX--;
	else if ((btnCode == 100)&&(moveRegulFigure(tempFigureX + 1, tempFigureY)))  //d
		tempFigureX++;

	controlPlayer(tempFigureX, tempFigureY);
}

void Game::controlPlayer(int playerX, int playerY)
{
	Figure* temp = level.player;
	level.arrayFigure[level.startPlayerY][level.startPlayerX] = nullptr;

	level.startPlayerX = playerX;
	level.startPlayerY = playerY;

	level.player = temp;
	if (level.arrayFigure[level.startPlayerY][level.startPlayerX] == nullptr)
	{
		level.arrayFigure[level.startPlayerY][level.startPlayerX] = level.player;
	}
	else if (level.arrayFigure[level.startPlayerY][level.startPlayerX]->coordFigure()->typeFigure == COIN)
	{
		level.arrayFigure[level.startPlayerY][level.startPlayerX] = level.player;
		if (level.timerEnergizer > 0) level.pointPlayer += 10;
		   else level.pointPlayer += 5;
	}
	else if (level.arrayFigure[level.startPlayerY][level.startPlayerX]->coordFigure()->typeFigure == ENERGIZER)
	{
		level.arrayFigure[level.startPlayerY][level.startPlayerX] = level.player;
		level.timerEnergizer += 5;
		//level.pointPlayer *= 2;
	}
};

void Game::setEatEnergizer() 
{
	setCountPointConsol(40, 5, level.timerEnergizer);
}

bool Game::moveRegulFigure(int positionX, int positionY)
{
	if ((positionX == 29) && (positionY == 11))
		tempFigureX = -1;
	else if ((positionX == 0) && (positionY == 11))
		tempFigureX = 30;
	else if ((positionX >= 0) && (positionY >= 0) && (positionX <= 29) && (positionY <= 19)) 
	{
		if ((level.arrayFigure[positionY][positionX] == nullptr)||(level.arrayFigure[positionY][positionX]->coordFigure()->typeFigure == COIN)) return TRUE;
		else if (level.arrayFigure[positionY][positionX]->coordFigure()->typeFigure == WALL) return FALSE;
	}
	else return FALSE;
}

void Game::UpdateF(float deltaTime)
 {
	sumTimer += deltaTime;
	//setCountPointConsol(40, 8, (int)sumTimer);

	if (level.timerEnergizer>0) 
	{ 
		setTimerEnergizerConsol(37, 3, level.timerEnergizer);
		sumTempTimer += deltaTime;
		if (sumTempTimer >= 1) 
		{
			//setCountPointConsol(40, 8, (int)sumTimer);
			level.timerEnergizer--;
			sumTempTimer = 0;
		}
	} 
	else setTextConsol(37, 3, 0, "  ");
}
