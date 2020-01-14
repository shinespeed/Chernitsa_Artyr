#include "stdafx.h"
#include "Level.h"
#include <time.h>
#include <stdlib.h>


Level::Level()
{
	playerX = startPlayerX = 14;
	playerY = startPlayerY = 12;

	level = 1;

	pointPlayer = 0;
	healthLevel = 5;
	quantityEnergizer = 5;
	quantityCoin = 0;

	timerEnergizer = 0;

	player = new Pacman();

	blinky = new Blinky();
	pinky = new Pinky();
	inky = new Inky();
	clyde = new Clyde();

	coin = new Coin();
	energizer = new Energizer();

	arrayFigure[playerY][playerX] = player;

	arrayFigure[blinky->coordFigure()->y][blinky->coordFigure()->x] = blinky;
	arrayFigure[pinky->coordFigure()->y][pinky->coordFigure()->x] = pinky;
	arrayFigure[inky->coordFigure()->y][inky->coordFigure()->x] = inky;
	arrayFigure[clyde->coordFigure()->y][clyde->coordFigure()->x] = clyde;

	arrayFigure[3][7] = energizer;

	updateEnergizer();
	updateCoin();
};

Level::~Level()
{
	//delete[] arrayFigure;
};

void Level::updateCoin()
{
	quantityCoin = 0;
	for (int i=0; i<20; i++)
		for (int j = 0; j < 40; j++) 
		{
			if (arrayFigure[i][j] == nullptr)
			{
				quantityCoin++;
				arrayFigure[i][j] = coin;
			}
		}
};

void Level::updateEnergizer(){

	srand(time(nullptr));
	int temp = quantityEnergizer;
	while(temp)
	{
		tempX = rand() % 40;
		tempY = rand() % 20;

		if (arrayFigure[tempY][tempX] == nullptr) 
		{ 
			arrayFigure[tempY][tempX] = energizer; 
			temp--;
		}
	}
}

void Level::movePlayer() 
{

}