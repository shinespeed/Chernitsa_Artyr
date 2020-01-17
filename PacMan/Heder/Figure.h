#ifndef FIGURE_H
#define FIGURE_H

#include "GlobalConst.h"

enum TypeFigure
{
	PACMAN,
	BLINKY,
	PINKY,
	INKY,
	CLAYDE,
	WALL,
	COIN,
	ENERGIZER,
	DECISIONPOINT
};

struct coord 
{
	int x;
	int y;
	int earlyX;
	int earlyY;
	int startX;
	int startY;
	float speed;
	TypeFigure typeFigure;
};

class Figure
{
public:

	Figure();
	virtual coord *coordFigure();
};

class Pacman: public Figure
{
public:
	Pacman(int x, int y);
	coord* coordFigure();

private:

	coord coordPacman;
};


class Ghost : public Figure
{
public:

	Ghost(int x, int y, TypeFigure typeFigure);
	coord* coordFigure();
private:

	coord coordGhost;

};


class Wall: public Figure
{
public:
	Wall();
	coord* coordFigure();

private:

	coord coordWall;
};


class Coin: public Figure
{
public:

	Coin();
	coord* coordFigure();
private:

	coord coordCoin;
};

class Energizer: public Figure 
{
public:
	Energizer();
	coord* coordFigure();

private:

	coord coordEnergizer;
};

class DecisionPoint : public Figure
{
public:
	DecisionPoint();
	coord* coordFigure();

private:
	coord coordDecisionPoint;

};

#endif