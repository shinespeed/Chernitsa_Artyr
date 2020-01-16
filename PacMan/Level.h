#ifndef LEVEL_H
#define LEVEL_H

#include "Figure.h"
#include "GlobalConst.h"

class Level
{
public:
	Level();
	~Level();

	int startPlayerX;
	int startPlayerY;
	int playerX;
	int playerY;

	int m_tempX;
	int m_tempY;

	int level;

	int pointCount;
	short healthLevel;
	int energizerCount;
	int coinCount;
	double speed;

	int timerEnergizer;

	Figure* w;
	Figure* d;
	
	Figure* player;

	Figure* blinky;
	Figure* pinky;
	Figure* inky;
	Figure* clyde;

	Figure* coin;
	Figure* energizer;

	Figure* arrayFigure[ARRAY_Y][ARRAY_X];
	Figure* arrayDecisionPoint[ARRAY_Y][ARRAY_X];

	void updateEnergizer();
	void updateCoin();
};

#endif