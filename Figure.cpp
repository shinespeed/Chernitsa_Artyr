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