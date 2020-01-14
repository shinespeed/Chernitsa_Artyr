#include "pch.h"
#include "stdafx.h"
#include "Figure.h"


Figure::Figure(){}

coord* Figure::coordFigure() {return nullptr;};

Pacman::Pacman()
{
	coordPacman.typeFigure = TypeFigure::PACMAN;
};

coord* Pacman::coordFigure() {return &coordPacman;};

Blinky::Blinky()
{
	coordBlinky.speed = 0;
	coordBlinky.earlyX = coordBlinky.x = 16;
	coordBlinky.earlyY = coordBlinky.y = 10;
	coordBlinky.typeFigure = TypeFigure::BLINKY;
};

coord* Blinky::coordFigure() { return &coordBlinky; };

Pinky::Pinky()
{
	coordPinky.speed = 0;
	coordPinky.earlyX = coordPinky.x = 15;
	coordPinky.earlyY = coordPinky.y = 10;
	coordPinky.typeFigure = TypeFigure::BLINKY;
};

coord* Pinky::coordFigure() { return &coordPinky; };

Inky::Inky()
{
	coordInky.speed = 0;
	coordInky.earlyX = coordInky.x = 14;
	coordInky.earlyY = coordInky.y = 10;
	coordInky.typeFigure = TypeFigure::INKY;
};

coord* Inky::coordFigure() { return &coordInky; };

Clyde::Clyde()
{
	coordClyde.speed = 0;
	coordClyde.earlyX = coordClyde.x = 13;
	coordClyde.earlyY = coordClyde.y = 10;
	coordClyde.typeFigure = TypeFigure::CLAYDE;
};

coord* Clyde::coordFigure() { return &coordClyde; };

Wall::Wall()
{
	coordWall.typeFigure = TypeFigure::WALL;
};

coord* Wall::coordFigure() { return &coordWall; };

Coin::Coin()
{
	coordCoin.typeFigure = TypeFigure::COIN;
};

coord* Coin::coordFigure() { return &coordCoin; };

Energizer::Energizer()
{
	coordEnergizer.typeFigure = TypeFigure::ENERGIZER;
};

coord* Energizer::coordFigure() { return &coordEnergizer; };

DecisionPoint::DecisionPoint()
{
	coordDecisionPoint.x = 0;
	coordDecisionPoint.x = 0;
	coordDecisionPoint.typeFigure = TypeFigure::DECISIONPOINT;
};

coord* DecisionPoint::coordFigure() { return &coordDecisionPoint; };

