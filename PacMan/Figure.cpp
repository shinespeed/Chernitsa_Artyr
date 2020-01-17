#include "pch.h"
#include "Figure.h"
#include "GlobalConst.h"

Figure::Figure(){}

coord* Figure::coordFigure() {return nullptr;};

Pacman::Pacman(int x, int y)
{
	coordPacman.typeFigure = TypeFigure::PACMAN;
	coordPacman.startX = coordPacman.earlyX = coordPacman.x = x;
	coordPacman.startY = coordPacman.earlyY = coordPacman.y = y;
};
coord* Pacman::coordFigure() {return &coordPacman;};

Ghost::Ghost(int x, int y, TypeFigure typeFigure)
{
	coordGhost.speed = 0;
	coordGhost.startX = coordGhost.earlyX = coordGhost.x = x;
	coordGhost.startY = coordGhost.earlyY = coordGhost.y = y;
	coordGhost.typeFigure = typeFigure;
};

coord* Ghost::coordFigure() { return &coordGhost; };

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
	coordDecisionPoint.typeFigure = TypeFigure::DECISIONPOINT;
};

coord* DecisionPoint::coordFigure() { return &coordDecisionPoint; };

