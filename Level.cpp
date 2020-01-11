#include "stdafx.h"
#include "Level.h"
#include <time.h>
#include <stdlib.h>


Level::Level()
{
	startPlayerX = 14;
	startPlayerY = 12;

	pointPlayer = 0;
	heartLevel = 5;
	quantityEnergizer = 5;

	timerEnergizer = 0;

	player = new Pacman();
	coin = new Coin();
	energizer = new Energizer();

	arrayFigure[startPlayerY][startPlayerX] = player;

	updateEnergizer();
	updateCoin();
};

void Level::updateLevel()
{
	startPlayerX = 14;
	startPlayerY = 12;

	pointPlayer = 0;
	heartLevel = 5;
	quantityEnergizer = 5;

	timerEnergizer = 0;

	player = new Pacman();
	coin = new Coin();
	energizer = new Energizer();

	arrayFigure[startPlayerY][startPlayerX] = player;

	updateEnergizer();
	updateCoin();
};

Level::~Level()
{
};

void Level::updateCoin()
{

	for (int i=0; i<20; i++)
		for (int j = 0; j < 40; j++) 
		{
			if (arrayFigure[i][j] == nullptr) arrayFigure[i][j] = coin;
		}
};

void Level::updateEnergizer(){

	srand(time(nullptr));

	while(quantityEnergizer)
	{
		tempX = rand() % 40;
		tempY = rand() % 20;

		if (arrayFigure[tempY][tempX] == nullptr) 
		{ 
			arrayFigure[tempY][tempX] = energizer; 
			quantityEnergizer--;
		}
	}
}