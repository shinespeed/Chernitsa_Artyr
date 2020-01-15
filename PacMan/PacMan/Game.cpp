#include "stdafx.h"
#include "Game.h"
#include "time.h"

Game::Game(): Parent(45, 21)
{
	mDirection = true;

	providinGhost = -1;

	temp = nullptr;
}

void Game::KeyPressed(int btnCode)
{

	if ((btnCode == 119) && (moveRegulFigure(level.player->coordFigure()->earlyX, level.player->coordFigure()->earlyY - 1))) //w
		level.player->coordFigure()->earlyY--;
	else if ((btnCode == 115)&&(moveRegulFigure(level.player->coordFigure()->earlyX, level.player->coordFigure()->earlyY + 1))) //s
		level.player->coordFigure()->earlyY++;
	else if ((btnCode == 97)&&(moveRegulFigure(level.player->coordFigure()->earlyX - 1, level.player->coordFigure()->earlyY))) //a
		level.player->coordFigure()->earlyX--;
	else if ((btnCode == 100)&&(moveRegulFigure(level.player->coordFigure()->earlyX + 1, level.player->coordFigure()->earlyY)))  //d
		level.player->coordFigure()->earlyX++;


	if ((level.player->coordFigure()->x == 29) && (level.player->coordFigure()->y == 11))
	{
		controlPlayer(1, 11);
	}
	else if ((level.player->coordFigure()->x == 0) && (level.player->coordFigure()->y == 11))
	{
		controlPlayer(28, 11);
	}
	else controlPlayer(level.player->coordFigure()->earlyX, level.player->coordFigure()->earlyY);

	
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
			level.timerEnergizer += 7;

			setTextConsol(43, 2, 0, "           ");
		}
	}

	level.arrayFigure[level.player->coordFigure()->y][level.player->coordFigure()->x] = nullptr;
	level.player->coordFigure()->earlyX = level.player->coordFigure()->x = playerX;
	level.player->coordFigure()->earlyY = level.player->coordFigure()->y = playerY;
	level.arrayFigure[level.player->coordFigure()->y][level.player->coordFigure()->x] = level.player;
};

void Game::updateLevel()
{
	controlPlayer(level.startPlayerX, level.startPlayerY);
	moveGhost(level.blinky, 14, 10);

	level.level++;

	level.quantityEnergizer = 5;
	level.healthLevel = 5;

	level.updateEnergizer();
	level.updateCoin();
	level.quantityCoin--;

	if (level.speed < 5)
	{
		level.speed -= 0.1;
	} else if (level.speed < 5) level.speed -= 0.025;

};


bool Game::moveRegulFigure(int positionX, int positionY)
{
    if ((positionX >= 0) && (positionY >= 0) && (positionX <= 29) && (positionY <= 19)) 
	{
		if ((level.arrayFigure[positionY][positionX] == nullptr)||(level.arrayFigure[positionY][positionX]->coordFigure()->typeFigure == COIN)) return TRUE;
		else if (level.arrayFigure[positionY][positionX]->coordFigure()->typeFigure == WALL) 
			return FALSE;
	}
	else return FALSE;
}

void Game::moveGhost(Figure* ghost, int x, int y) 
{
	level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX] = temp;

	ghost->coordFigure()->earlyX = x;
	ghost->coordFigure()->earlyY = y;

	if (level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX] != level.player)
		temp = level.arrayFigure[ghost->coordFigure()->earlyY][ghost->coordFigure()->earlyX];
	else temp = nullptr;

	ghost->coordFigure()->x = x;
	ghost->coordFigure()->y = y;

	level.arrayFigure[ghost->coordFigure()->y][ghost->coordFigure()->x] = ghost;
}

void Game::directionGhost(Figure* ghost, int providingDirection)
{

	if (providingDirection == 1) //DOWN
	{
		moveGhost(ghost, ghost->coordFigure()->x , ghost->coordFigure()->y + 1);
	}


	else if (providingDirection == 2) //UP
	{
		moveGhost(ghost, ghost->coordFigure()->x, ghost->coordFigure()->y - 1);
	}


	else if (providingDirection == 3) //LEFT
	{
		moveGhost(ghost, ghost->coordFigure()->x - 1, ghost->coordFigure()->y);
	}


	else if (providingDirection == 4)
	{
		moveGhost(ghost, ghost->coordFigure()->x + 1, ghost->coordFigure()->y);
	}


}

void Game::controlMoveGhost(Figure* ghost) 
{
	
	if ((ghost->coordFigure()->x == 29) && (ghost->coordFigure()->y == 11))
	{
		moveGhost(ghost, 0, 11);
	}
	else if ((ghost->coordFigure()->x == 0) && (ghost->coordFigure()->y == 11))
	{
		moveGhost(ghost, 29, 11);;
	}

	if ((level.arrayDecisionPoint[ghost->coordFigure()->y][ghost->coordFigure()->x] != nullptr)&&(level.timerEnergizer == 0))
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
		else providinGhost = 0;
	}
	directionGhost(ghost, providinGhost);
}

int Game::providingDirection(Figure* ghost)
{
	float min[4];
	float m_min = 0;
	int decision = 1;


	if ((moveRegulFigure(ghost->coordFigure()->x, ghost->coordFigure()->y + 1)) && (providinGhost != 2))
	{
		min[0] = sqrt(pow((ghost->coordFigure()->x - level.player->coordFigure()->x), 2) + pow(((ghost->coordFigure()->y + 1) - level.player->coordFigure()->y), 2));
	}
	else min[0] = 100;

	if ((moveRegulFigure(ghost->coordFigure()->x, ghost->coordFigure()->y - 1)) && (providinGhost != 1))
	{
		min[1] = sqrt(pow((ghost->coordFigure()->x  - level.player->coordFigure()->x), 2) + pow(((ghost->coordFigure()->y - 1) - level.player->coordFigure()->y), 2));
	}
	else min[1] = 100;

	if ((moveRegulFigure(ghost->coordFigure()->x - 1, ghost->coordFigure()->y)) && (providinGhost != 4))
	{
		min[2] = sqrt(pow((ghost->coordFigure()->x - 1  - level.player->coordFigure()->x), 2) + pow(((ghost->coordFigure()->y) - level.player->coordFigure()->y), 2));
	}
	else min[2] = 100;

	if ((moveRegulFigure(ghost->coordFigure()->x + 1, ghost->coordFigure()->y)) && (providinGhost != 3))
	{
		min[3] = sqrt(pow((ghost->coordFigure()->x + 1 - level.player->coordFigure()->x), 2) + pow(((ghost->coordFigure()->y ) - level.player->coordFigure()->y), 2));
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

void Game::controlGhost(float deltaTime, Figure* ghost, double speed) 
{

	if ((level.healthLevel>0)&& 
		(ghost->coordFigure()->x == level.player->coordFigure()->x) && 
		(ghost->coordFigure()->y == level.player->coordFigure()->y) &&
		(level.timerEnergizer == 0))
	{

		level.healthLevel--;

		controlPlayer(level.startPlayerX, level.startPlayerY);

		ghost->coordFigure()->earlyX = ghost->coordFigure()->x = 16;
		ghost->coordFigure()->earlyY = ghost->coordFigure()->y = 10;

	} 
	else if ((level.timerEnergizer > 0) &&
		(ghost->coordFigure()->x == level.player->coordFigure()->x) &&
		(ghost->coordFigure()->y == level.player->coordFigure()->y))
	{ 
  
		level.pointPlayer +=200;

		ghost->coordFigure()->earlyX = ghost->coordFigure()->x = 16;
		ghost->coordFigure()->earlyY = ghost->coordFigure()->y = 10;


		controlPlayer(level.player->coordFigure()->x, level.player->coordFigure()->y);

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
	setCountPointConsol(38, 3, level.quantityCoin);
	setHealthLevel(33, 4, level.healthLevel);


	if (level.timerEnergizer > 0)
	{

		setTimerEnergizerConsol(42, 3, level.timerEnergizer);

	} else setTextConsol(42, 3, 0, "  ");
    

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 30; j++)
		{
			if (level.arrayFigure[i][j] == nullptr)
			{
				SetChar(j + 1, i + 1, 0, L' ');
			}
			else if (level.timerEnergizer < 1) 
			{
				switch (level.arrayFigure[i][j]->coordFigure()->typeFigure)
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
			else 
			{
				switch (level.arrayFigure[i][j]->coordFigure()->typeFigure)
				{
				case PACMAN: SetChar(j + 1, i + 1, 6, 2); break;
				case WALL:	SetChar(j + 1, i + 1, 1, 10); break;
				case COIN:	SetChar(j + 1, i + 1, 7, 7); break;
				case ENERGIZER: SetChar(j + 1, i + 1, 4, 5); break;

				case BLINKY: SetChar(j + 1, i + 1, 7, 1); break;
				case PINKY: SetChar(j + 1, i + 1, 7, 1); break;
				case INKY: SetChar(j + 1, i + 1, 7, 1); break;
				case CLAYDE: SetChar(j + 1, i + 1, 7, 1); break;
				}
			}
		}
	}
}

bool Game::Update(float deltaTime)
 {

	Render();
    
	setTextConsol(38, 10, 0, "     ");

	sumTimer += deltaTime;

	//controlGhost(sumTimer, level.pinky);
	controlGhost(deltaTime, level.blinky, level.speed );

	///if (level.quantityCoin < 240)
	//{
	//	controlGhost(deltaTime, level.inky, 0.8);
	//}

	if ((sumTimer >= 2)&&(level.timerEnergizer > 0))
	{
		level.timerEnergizer--;
		sumTimer = 0;
	}

	if (level.healthLevel != 0) return TRUE;
	else return FALSE;
}
