#pragma once

#include "Figure.h"

class Level
{
private:

	Figure* w = new Wall();

public:

	int startPlayerX;
	int startPlayerY;

	int tempX;
	int tempY;

	int pointPlayer;
	int heartLevel;
	int quantityEnergizer;

	int timerEnergizer;

	Figure* player;

	Figure* coin;
	Figure* energizer;

	Figure* arrayFigure[20][30] =  { { w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w},
	                                 { w,0,0,0,0,0,0,0,0,0,0,0,0,0,w,w,0,0,0,0,0,0,0,0,0,0,0,0,0,w},
						             { w,0,w,w,w,w,0,0,w,w,w,w,0,0,w,w,0,0,w,w,w,w,0,0,w,w,w,w,0,w},
					               	 { w,0,w,w,w,w,0,0,w,w,w,w,0,0,w,w,0,0,w,w,w,w,0,0,w,w,w,w,0,w},
						             { w,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,w},
						             { w,0,0,0,0,0,0,0,w,0,0,w,w,w,w,w,w,w,w,0,0,w,0,0,0,0,0,0,0,w},
						             { w,0,w,w,w,w,0,0,w,0,0,0,0,0,w,w,0,0,0,0,0,w,0,0,w,w,w,w,0,w},
						             { w,0,0,0,0,0,0,0,w,w,w,w,w,0,w,w,0,w,w,w,w,w,0,0,0,0,0,0,0,w},
						             { w,0,w,w,w,w,0,0,w,0,0,0,0,0,0,0,0,0,0,0,0,w,0,0,w,w,w,w,0,w},
						             { w,0,0,0,0,0,0,0,w,0,0,0,w,w,0,0,w,w,0,0,0,w,0,0,0,0,0,0,0,w},
						             { w,w,w,w,w,w,0,0,0,0,w,0,w,0,0,0,0,w,0,w,0,0,0,0,w,w,w,w,w,w},
					                 { 0,0,0,0,0,0,0,0,w,0,0,0,w,w,w,w,w,w,0,0,0,w,0,0,0,0,0,0,0,0},
						             { w,w,w,w,w,w,0,0,w,0,0,0,0,0,0,0,0,0,0,0,0,w,0,0,w,w,w,w,w,w},
					            	 { w,0,0,0,0,0,0,0,w,w,w,w,w,0,0,0,0,w,w,w,w,w,0,0,0,0,0,0,0,w},
						             { w,0,w,w,w,w,0,0,w,0,0,0,0,0,w,w,0,0,0,0,0,w,0,0,w,w,w,w,0,w},
						             { w,0,0,0,0,0,0,0,w,0,0,0,0,0,w,w,0,0,0,0,0,w,0,0,0,0,0,0,0,w},
						             { w,0,w,w,w,w,0,0,0,0,0,w,w,w,w,w,w,w,w,0,0,0,0,0,w,w,w,w,0,w},
						             { w,0,w,w,w,w,0,0,w,0,0,0,0,0,0,0,0,0,0,0,0,w,0,0,w,w,w,w,0,w},
						             { w,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,w},
						             { w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w,w},
	                               };

	Level();
	~Level();
	void updateEnergizer();
	void updateCoin();
	void updateLevel();
};

