#include <memory>
#include <iostream>
#include <time.h>
#include "stdlib.h"
#include "Level.h"
#include "Figure.h"
#include "GlobalConst.h"

Level::Level(): 
    d(new DecisionPoint()),
    w(new Wall()),
    arrayFigure
    {
	    { w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w},
	    { w,0,0,0,0,0,0,0,0,0,0,0,0,0,w,w,0,0,0,0,0,0,0,0,0,0,0,0,0,w},
	    { w,0,w,w,w,w,w,0,w,w,w,w,w,0,w,w,0,w,w,w,w,w,0,w,w,w,w,w,0,w},
	    { w,0,w,w,w,w,w,0,w,w,w,w,w,0,w,w,0,w,w,w,w,w,0,w,w,w,w,w,0,w},
	    { w,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,w},
	    { w,0,w,w,w,w,w,0,w,0,w,w,w,w,w,w,w,w,w,w,0,w,0,w,w,w,w,w,0,w},
	    { w,0,0,0,0,0,0,0,w,0,0,0,0,0,w,w,0,0,0,0,0,w,0,0,0,0,0,0,0,w},
	    { w,0,w,w,w,w,w,0,w,w,w,w,w,0,w,w,0,w,w,w,w,w,0,w,w,w,w,w,0,w},
	    { w,0,0,0,0,0,0,0,w,0,0,0,0,0,0,0,0,0,0,0,0,w,0,0,0,0,0,0,0,w},
	    { w,w,w,w,w,w,w,0,w,0,w,0,w,w,0,0,w,w,0,w,0,w,0,w,w,w,w,w,w,w},
	    { w,w,w,w,w,w,w,0,0,0,w,0,w,0,0,0,0,w,0,w,0,0,0,w,w,w,w,w,w,w},
	    { 0,0,0,0,0,0,0,0,w,0,w,0,w,w,w,w,w,w,0,w,0,w,0,0,0,0,0,0,0,0},
	    { w,w,w,w,w,w,w,0,w,0,0,0,0,0,0,0,0,0,0,0,0,w,0,w,w,w,w,w,w,w},
	    { w,w,w,w,w,w,w,0,w,w,w,w,w,0,w,w,0,w,w,w,w,w,0,w,w,w,w,w,w,w},
	    { w,0,0,0,0,0,0,0,w,0,0,0,0,0,w,w,0,0,0,0,0,w,0,0,0,0,0,0,0,w},
	    { w,0,w,w,w,w,w,0,w,0,w,w,w,w,w,w,w,w,w,w,0,w,0,w,w,w,w,w,0,w},
	    { w,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,w},
	    { w,0,w,w,w,w,w,0,w,0,w,w,w,w,w,w,w,w,w,w,0,w,0,w,w,w,w,w,0,w},
	    { w,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,w},
	    { w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w},
    },

    arrayDecisionPoint
    {
	    { w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w},
	    { w,0,0,0,0,0,0,d,0,0,0,0,0,0,w,w,0,0,0,0,0,0,d,0,0,0,0,0,0,w},
	    { w,0,w,w,w,w,w,0,w,w,w,w,w,0,w,w,0,w,w,w,w,w,0,w,w,w,w,w,0,w},
	    { w,0,w,w,w,w,w,0,w,w,w,w,w,0,w,w,0,w,w,w,w,w,0,w,w,w,w,w,0,w},
	    { w,d,0,0,0,0,0,d,0,d,0,0,0,d,0,0,d,0,0,0,d,0,d,0,0,0,0,0,d,w},
	    { w,0,w,w,w,w,w,0,w,0,w,w,w,w,w,w,w,w,w,w,0,w,0,w,w,w,w,w,0,w},
	    { w,d,0,0,0,0,0,d,w,0,0,0,0,0,w,w,0,0,0,0,0,w,d,0,0,0,0,0,d,w},
	    { w,0,w,w,w,w,w,0,w,w,w,w,w,0,w,w,0,w,w,w,w,w,0,w,w,w,w,w,0,w},
	    { w,0,0,0,0,0,0,d,w,0,0,d,0,d,0,0,d,0,d,0,0,w,d,0,0,0,0,0,0,w},
	    { w,w,w,w,w,w,w,0,w,0,w,0,w,w,0,0,w,w,0,w,0,w,0,w,w,w,w,w,w,w},
	    { w,w,w,w,w,w,w,d,0,d,w,0,w,0,0,0,0,w,0,w,d,0,d,w,w,w,w,w,w,w},
	    { 0,0,0,0,0,0,0,d,w,0,w,0,w,w,w,w,w,w,0,w,0,w,d,0,0,0,0,0,0,0},
	    { w,w,w,w,w,w,w,0,w,0,0,d,0,d,0,0,d,0,d,0,0,w,0,w,w,w,w,w,w,w},
	    { w,w,w,w,w,w,w,0,w,w,w,w,w,0,w,w,0,w,w,w,w,w,0,w,w,w,w,w,w,w},
	    { w,0,0,0,0,0,0,d,w,0,0,0,0,0,w,w,0,0,0,0,0,w,d,0,0,0,0,0,0,w},
	    { w,0,w,w,w,w,w,0,w,0,w,w,w,w,w,w,w,w,w,w,0,w,0,w,w,w,w,w,0,w},
	    { w,d,0,0,0,0,0,d,0,d,0,0,0,0,0,0,0,0,0,0,d,0,d,0,0,0,0,0,d,w},
	    { w,0,w,w,w,w,w,0,w,0,w,w,w,w,w,w,w,w,w,w,0,w,0,w,w,w,w,w,0,w},
	    { w,0,0,0,0,0,0,d,0,d,0,0,0,0,0,0,0,0,0,0,d,0,d,0,0,0,0,0,0,w},
	    { w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w},

    },

    level(1),
    speed (0.04),
    pointCount(0),
    healthLevel(5),
    energizerCount(5),
    coinCount(0),
    timerEnergizer(0)

{	
	player = new Pacman(1, 18);

	blinky = new  Ghost(STARTGHOSTX, STARTGHOSTY, TypeFigure::BLINKY);
	pinky = new Ghost(STARTGHOSTX + 2, STARTGHOSTY, TypeFigure::PINKY);
	inky = new Ghost(STARTGHOSTX - 1, STARTGHOSTY, TypeFigure::INKY);
	clyde = new Ghost(STARTGHOSTX + 1, STARTGHOSTY, TypeFigure::CLAYDE);

	coin = new Coin();
	energizer = new Energizer();

	startPlayerX = player->coordFigure()->earlyX;
	startPlayerY = player->coordFigure()->earlyY;

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
	delete[] arrayFigure;
	delete[] arrayDecisionPoint;

	delete w;
	delete d;

	delete player;

	delete blinky;
	delete pinky;
	delete inky;
	delete clyde;

	delete coin;
	delete energizer;
};

void Level::updateCoin()
{
	coinCount = 0;
	for (int i = 0; i < ARRAY_Y; i++)
	{
		for (int j = 0; j < ARRAY_X; j++)
		{
			if (arrayFigure[i][j] == nullptr)
			{
				coinCount++;
				arrayFigure[i][j] = coin;
			}
		}
	}
};

void Level::updateEnergizer()
{
	srand(time(nullptr));
	int m_temp = energizerCount;
	while(m_temp)
	{
		m_tempX = rand() % 40;
		m_tempY = rand() % 20;

		if (arrayFigure[m_tempY][m_tempX] == nullptr) 
		{ 
			arrayFigure[m_tempY][m_tempX] = energizer; 
			m_temp--;
		}
	}
}
