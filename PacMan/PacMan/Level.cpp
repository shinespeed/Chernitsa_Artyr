#include "stdafx.h"
#include "Level.h"
#include <time.h>
#include <stdlib.h>


Level::Level()
{

	player = new Pacman(1, 18);

	blinky = new Blinky(14, 10);
	pinky = new Pinky(16, 10);
	inky = new Inky(13, 10);
	clyde = new Clyde(15, 10);

	coin = new Coin();
	energizer = new Energizer();

	startPlayerX = player->coordFigure()->earlyX;
	startPlayerY = player->coordFigure()->earlyY;

	level = 1;
	speed = 1;

	pointPlayer = 0;
	healthLevel = 5;
	quantityEnergizer = 5;
	quantityCoin = 0;

	timerEnergizer = 0;

	arrayFigure[player->coordFigure()->y][player->coordFigure()->x] = player;

	arrayFigure[blinky->coordFigure()->y][blinky->coordFigure()->x] = blinky;
	arrayFigure[pinky->coordFigure()->y][pinky->coordFigure()->x] = pinky;
	arrayFigure[inky->coordFigure()->y][inky->coordFigure()->x] = inky;
	arrayFigure[clyde->coordFigure()->y][clyde->coordFigure()->x] = clyde;

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
