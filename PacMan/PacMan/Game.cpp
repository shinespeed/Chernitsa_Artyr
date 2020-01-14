#include "stdafx.h"
#include "Game.h"
#include "time.h"

Game::Game(): Parent(45, 21)
{
	mDirection = true;

	tempX = 0;
	tempY = 0;

	tempFigureX = level.playerX;
	tempFigureY = level.playerY;

	sumTempTimer = 0;
	providinGhost = -1;

	temp = nullptr;
}

void Game::KeyPressed(int btnCode)
{
	if ((btnCode == 119)&&(moveRegulFigure(tempFigureX, tempFigureY-1))) //w
		tempFigureY--;
	else if ((btnCode == 115)&&(moveRegulFigure(tempFigureX, tempFigureY + 1))) //s
		tempFigureY++;
	else if ((btnCode == 97)&&(moveRegulFigure(tempFigureX - 1, tempFigureY))) //a
		tempFigureX--;
	else if ((btnCode == 100)&&(moveRegulFigure(tempFigureX + 1, tempFigureY)))  //d
		tempFigureX++;

	controlPlayer(tempFigureX, tempFigureY);

	if ((level.quantityCoin == 0) && (level.quantityEnergizer == 0)) 
	{
		updateLevel();
	}
}

void Game::controlPlayer(int playerX, int playerY)
{
	if (level.arrayFigure[playerY][playerX] != nullptr)
	{
		if (level.arrayFigure[playerY][playerX]->coordFigure()->typeFigure == COIN)
		{
			level.quantityCoin--;
			level.arrayFigure[playerY][playerX] = level.player;
			if (level.timerEnergizer > 0) level.pointPlayer += 10; 
			else level.pointPlayer += 5;
		}
		else if (level.arrayFigure[playerY][playerX]->coordFigure()->typeFigure == ENERGIZER)
		{
			level.quantityEnergizer--;
			level.arrayFigure[playerY][playerX] = level.player;
			level.timerEnergizer += 5;

			setTextConsol(43, 2, 0, "           ");
		}
	}

	level.arrayFigure[level.playerY][level.playerX] = nullptr;
	tempFigureX = level.playerX = playerX;
	tempFigureY = level.playerY = playerY;
	level.arrayFigure[level.playerY][level.playerX] = level.player;
};

void Game::updateLevel()
{
	controlPlayer(level.startPlayerX, level.startPlayerY);

	level.level++;

	level.quantityEnergizer = 5;
	level.healthLevel = 5;

	level.updateEnergizer();
	level.updateCoin();
	level.quantityCoin--;
};

void Game::setEatEnergizer() 
{
	setCountPointConsol(40, 5, level.timerEnergizer);
}

bool Game::moveRegulFigure(int positionX, int positionY)
{
	if ((positionX == 30) && (positionY == 11))
		tempFigureX = -1;
	else if ((positionX == -1) && (positionY == 11))
		tempFigureX = 30;
	else if ((positionX >= 0) && (positionY >= 0) && (positionX <= 29) && (positionY <= 19)) 
	{
		if ((level.arrayFigure[positionY][positionX] == nullptr)||(level.arrayFigure[positionY][positionX]->coordFigure()->typeFigure == COIN)) return TRUE;
		else if (level.arrayFigure[positionY][positionX]->coordFigure()->typeFigure == WALL) return FALSE;
	}
	else return FALSE;
}

void Game::moveGhost(Figure* ghost, int providingDirection)
{

	if (providingDirection == 1) //DOWN
	{
		level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX] = temp;

		ghost->coordFigure()->earlyX = ghost->coordFigure()->x;
		ghost->coordFigure()->earlyY += 1;

		if (level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX] != level.player)
			temp = level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX];
		else temp = nullptr;

		ghost->coordFigure()->y += 1;

		level.arrayFigure[ghost->coordFigure()->y][ghost->coordFigure()->x] = ghost;
	}


	else if (providingDirection == 2) //UP
	{

		level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX] = temp;

		ghost->coordFigure()->earlyX = ghost->coordFigure()->x;
		ghost->coordFigure()->earlyY--;

		if (level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX] != level.player)
			temp = level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX];
		else temp = nullptr;

		ghost->coordFigure()->y--;

		level.arrayFigure[ghost->coordFigure()->y][ghost->coordFigure()->x] = ghost;
	}


	else if (providingDirection == 3) //LEFT
	{
		level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX] = temp;


		ghost->coordFigure()->earlyX -= 1;
		ghost->coordFigure()->earlyY = ghost->coordFigure()->y;

		if (level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX] != level.player)
			temp = level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX];
		else temp = nullptr;

		ghost->coordFigure()->x -= 1;

		level.arrayFigure[ghost->coordFigure()->y][ghost->coordFigure()->x] = ghost;
	}


	else if (providingDirection == 4)
	{
		level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX] = temp;

		ghost->coordFigure()->earlyX += 1;
		ghost->coordFigure()->earlyY = ghost->coordFigure()->y;

		if (level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX] != level.player)
			temp = level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX];
		else temp = nullptr;

		ghost->coordFigure()->x += 1;

		level.arrayFigure[ghost->coordFigure()->y][ghost->coordFigure()->x] = ghost;
	}


}

void Game::controlMoveGhost(Figure* ghost) 
{
	
	
	if (level.arrayDecisionPoint[ghost->coordFigure()->y][ghost->coordFigure()->x] != nullptr)
	{
		if (level.arrayDecisionPoint[ghost->coordFigure()->y][ghost->coordFigure()->x]->coordFigure()->typeFigure == TypeFigure::DECISIONPOINT)
		{
			providinGhost = providingDirection(ghost);
		}
	}

	else
	
	{
		if (moveRegulFigure(ghost->coordFigure()->x, ghost->coordFigure()->y - 1) && (providinGhost != 1))
		{
			providinGhost = 2;
		}

		else if ((moveRegulFigure(ghost->coordFigure()->x - 1, ghost->coordFigure()->y)) && (providinGhost != 4))
		{
			providinGhost = 3;
		}

		else if (moveRegulFigure(ghost->coordFigure()->x + 1, ghost->coordFigure()->y) && (providinGhost != 3))
		{
			providinGhost = 4;
		}
		else if (moveRegulFigure(ghost->coordFigure()->x, ghost->coordFigure()->y + 1) && (providinGhost != 2))
		{
			providinGhost = 1;
		}
	}
	moveGhost(ghost, providinGhost);
}

int Game::providingDirection(Figure* ghost)
{
	float min[4];
	float m_min = 0;
	int decision = 1;


	if ((moveRegulFigure(ghost->coordFigure()->x, ghost->coordFigure()->y + 1)) && (providinGhost != 2))
	{
		min[0] = sqrt(pow((ghost->coordFigure()->x - level.playerX), 2) + pow(((ghost->coordFigure()->y + 1) - level.playerY), 2));
	}
	else min[0] = 100;

	if ((moveRegulFigure(ghost->coordFigure()->x, ghost->coordFigure()->y - 1)) && (providinGhost != 1))
	{
		min[1] = sqrt(pow((ghost->coordFigure()->x  - level.playerX), 2) + pow(((ghost->coordFigure()->y - 1) - level.playerY), 2));
	}
	else min[1] = 100;

	if ((moveRegulFigure(ghost->coordFigure()->x - 1, ghost->coordFigure()->y)) && (providinGhost != 4))
	{
		min[2] = sqrt(pow((ghost->coordFigure()->x - 1  - level.playerX), 2) + pow(((ghost->coordFigure()->y) - level.playerY), 2));
	}
	else min[2] = 100;

	if ((moveRegulFigure(ghost->coordFigure()->x + 1, ghost->coordFigure()->y)) && (providinGhost != 3))
	{
		min[3] = sqrt(pow((ghost->coordFigure()->x + 1 - level.playerX), 2) + pow(((ghost->coordFigure()->y ) - level.playerY), 2));
	}
	else min[3] = 100;


	m_min = min[0];
	for (int i = 0; i < 4; i++)
	{
		if (m_min > min[i])
		{
			decision = i + 1;
			m_min = min[i];
		}
	}

	return decision;
}

void Game::controlGhost(float deltaTime, Figure* ghost, float speed) 
{

	if ((ghost->coordFigure()->x == level.playerX) && (ghost->coordFigure()->y == level.playerY)) 
	{
		level.healthLevel--;
		controlPlayer(level.startPlayerX,level.startPlayerY);
	}
	ghost->coordFigure()->speed += deltaTime;
	if (ghost->coordFigure()->speed >= speed)
	{
		controlMoveGhost(ghost);
		ghost->coordFigure()->speed = 0;
	}

}

void Game::Render()
{
	setLevelConsol(41, 1, level.level);
	setTextConsol(38, 3, 7, "00000");
	setCountPointConsol(38, 3, level.pointPlayer);
	setHealthLevel(33, 4, level.healthLevel);

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (level.arrayFigure[i][j] == nullptr)
			{
				SetChar(j + 1, i + 1, 0, L' ');
			}
			else switch (level.arrayFigure[i][j]->coordFigure()->typeFigure)
			{
			   case PACMAN: SetChar(j + 1, i + 1, 6, 2); break;
			   case WALL:	SetChar(j + 1, i + 1, 1, 10); break;
			   case COIN:	SetChar(j + 1, i + 1, 7, 7); break;
			   case ENERGIZER: SetChar(j + 1, i + 1, 4, 5); break;
			   case BLINKY: SetChar(j + 1, i + 1, 4, 1); break;
			   case PINKY: SetChar(j + 1, i + 1, 5, 1); break;
			   case INKY: SetChar(j + 1, i + 1, 3, 1); break;
			   case CLAYDE: SetChar(j + 1, i + 1, 14, 1); break;
			}
		}
	}
}

bool Game::Update(float deltaTime)
 {

	Render();
    
	setTextConsol(38, 10, 0, "     ");
	setCountPointConsol(38, 10, providingDirection(level.pinky));

	sumTimer += deltaTime;

	//controlGhost(sumTimer, level.pinky);

	controlGhost(deltaTime, level.blinky, 0.9);

	if (level.quantityCoin < 240)
	{
		controlGhost(deltaTime, level.inky, 0.8);
	}

	if (level.timerEnergizer>0) 
	{ 
		setTimerEnergizerConsol(42, 3, level.timerEnergizer);
	
		if (sumTimer >= 2)
		{
			//setCountPointConsol(40, 8, (int)sumTimer);

			level.timerEnergizer--;
			sumTimer = 0;
		}
	} else setTextConsol(42, 3, 0, "  ");

	if (level.healthLevel != 0) return TRUE;
	else return FALSE;
}
