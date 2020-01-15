#pragma once

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
private:

	coord coordPacman;

public:

	Pacman(int x, int y);

	coord* coordFigure();
};


class Blinky : public Figure
{
private:

	coord coordBlinky;

public:

	Blinky(int x, int y);

	coord* coordFigure();
};

class Pinky : public Figure
{
private:

	coord coordPinky;

public:

	Pinky(int x, int y);

	coord* coordFigure();
};

class Inky : public Figure
{
private:

	coord coordInky;

public:

	Inky(int x, int y);

	coord* coordFigure();
};

class Clyde : public Figure
{
private:

	coord coordClyde;

public:

	Clyde(int x, int y);

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

class DecisionPoint : public Figure
{
private:

	coord coordDecisionPoint;

public:

	DecisionPoint();
	coord* coordFigure();

};
