#pragma once

#include "Figure.h"

class Level
{
private:

	Figure* w = new Wall();
	Figure* d = new DecisionPoint();

public:

	int startPlayerX;
	int startPlayerY;
	int playerX;
	int playerY;

	int tempX;
	int tempY;

	int level;

	int pointPlayer;
	int healthLevel;
	int quantityEnergizer;
	int quantityCoin;

	int timerEnergizer;

	Figure* player;

	Figure* blinky;
	Figure* pinky;
	Figure* inky;
	Figure* clyde;

	Figure* coin;
	Figure* energizer;

	Figure* arrayFigure[20][30] =   
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
    };

	Figure* arrayDecisionPoint[20][30] = 
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

	};

	Level();
	~Level();
	void updateEnergizer();
	void updateCoin();
	void movePlayer();
};

