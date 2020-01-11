#pragma once

enum TypeFigure
{
	PACMAN,
	WALL,
	COIN,
	ENERGIZER
};

struct coord 
{
	int x;
	int y;
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
private:

	coord coordPacman;

public:

	Pacman();

	coord* coordFigure();
};

class Wall: public Figure
{
private:

	coord coordWall;

public:

	Wall();
	coord* coordFigure();

};

class Coin: public Figure
{
private:

	coord coordCoin;

public:

	Coin();
	coord* coordFigure();

};

class Energizer: public Figure 
{
private:
	
	coord coordEnergizer;

public:

	Energizer();
	coord* coordFigure();

};
