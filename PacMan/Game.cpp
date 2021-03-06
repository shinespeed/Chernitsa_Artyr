#include "Game.h"
#include "time.h"
#include "Level.h"
#include "Figure.h"
#include "GlobalConst.h"

Game::Game(): 
	BaseApp(X_SIZE, Y_SIZE), 
	mDirection(true), 
	m_providinGhost(-1), 
	m_temp(nullptr)
{}
Game::~Game() 
{
	delete m_temp;
}
void Game::KeyPressed(int btnCode)
{
	if ((btnCode == UP) && (moveRegulFigure(level.player->coordFigure()->earlyX, level.player->coordFigure()->earlyY - 1))) //w
	{
		level.player->coordFigure()->earlyY--;
	}
	else if ((btnCode == DOWN) && (moveRegulFigure(level.player->coordFigure()->earlyX, level.player->coordFigure()->earlyY + 1))) //s
	{
		level.player->coordFigure()->earlyY++;
	}
	else if ((btnCode == LEFT) && (moveRegulFigure(level.player->coordFigure()->earlyX - 1, level.player->coordFigure()->earlyY))) //a
	{
		level.player->coordFigure()->earlyX--;
	}
	else if ((btnCode == RIGHT) && (moveRegulFigure(level.player->coordFigure()->earlyX + 1, level.player->coordFigure()->earlyY)))  //d
	{
		level.player->coordFigure()->earlyX++;
	}

	if ((level.player->coordFigure()->x == RIGHT_TELEPORT_X) && (level.player->coordFigure()->y == TELEPORT_Y))
	{
		controlPlayer(LEFT_TELEPORT_X + 1, TELEPORT_Y);
	}
	else if ((level.player->coordFigure()->x == LEFT_TELEPORT_X) && (level.player->coordFigure()->y == TELEPORT_Y))
	{
		controlPlayer(RIGHT_TELEPORT_X -1, TELEPORT_Y);
	}
	else controlPlayer(level.player->coordFigure()->earlyX, level.player->coordFigure()->earlyY);
	
	if ((level.coinCount == 0) && (level.energizerCount == 0)) 
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
			level.coinCount--;
			level.arrayFigure[playerY][playerX] = level.player;
			if (level.timerEnergizer > 0) level.pointCount += 10; 
			else level.pointCount += 5;
		}
		else if (level.arrayFigure[playerY][playerX]->coordFigure()->typeFigure == ENERGIZER)
		{
			level.energizerCount--;
			level.arrayFigure[playerY][playerX] = level.player;
			level.timerEnergizer += 7;

			setTextConsol(43, 2, BLACK, "           ");
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
	moveGhost(level.blinky, level.blinky->coordFigure()->startX, level.blinky->coordFigure()->startX);

	level.level++;

	level.energizerCount = 5;
	level.healthLevel = 5;

	level.updateEnergizer();
	level.updateCoin();
	level.coinCount--;

	if (level.speed < 5)
	{
		level.speed -= 0.1;
	}
	else if (level.speed < 5)
	{
		level.speed -= 0.005;
	}
};

bool Game::moveRegulFigure(int positionX, int positionY)
{
    if ((positionX >= 0) && (positionY >= 0) && (positionX <= 29) && (positionY <= 19)) 
	{
		if ((level.arrayFigure[positionY][positionX] == nullptr) || (level.arrayFigure[positionY][positionX]->coordFigure()->typeFigure == COIN))
		{
			return true;
		}
		else if (level.arrayFigure[positionY][positionX]->coordFigure()->typeFigure == WALL)
		{
			return false;
		}
	}
	else
	{
		return false;
	}
}

void Game::moveGhost(Figure* Ghost, int x, int y) 
{
	level.arrayFigure[Ghost->coordFigure()->earlyY][Ghost->coordFigure()->earlyX] = m_temp;

	Ghost->coordFigure()->earlyX = x;
	Ghost->coordFigure()->earlyY = y;

	if (level.arrayFigure[Ghost->coordFigure()->earlyY][Ghost->coordFigure()->earlyX] != level.player)
	{
		m_temp = level.arrayFigure[Ghost->coordFigure()->earlyY][Ghost->coordFigure()->earlyX];
	}	
	else
	{
		m_temp = nullptr;
	}

	Ghost->coordFigure()->x = x;
	Ghost->coordFigure()->y = y;

	level.arrayFigure[Ghost->coordFigure()->y][Ghost->coordFigure()->x] = Ghost;
}

void Game::directionGhost(Figure* Ghost, int providingDirection)
{
	if (providingDirection == DOWN_DIRECTION) //DOWN
	{
		moveGhost(Ghost, Ghost->coordFigure()->x , Ghost->coordFigure()->y + 1);
	}
	else if (providingDirection == UP_DIRECTION) //UP
	{
		moveGhost(Ghost, Ghost->coordFigure()->x, Ghost->coordFigure()->y - 1);
	}
	else if (providingDirection == LEFT_DIRECTION) //LEFT
	{
		moveGhost(Ghost, Ghost->coordFigure()->x - 1, Ghost->coordFigure()->y);
	}
	else if (providingDirection == RIGHT_DIRECTION)
	{
		moveGhost(Ghost, Ghost->coordFigure()->x + 1, Ghost->coordFigure()->y);
	}
}

void Game::controlMoveGhost(Figure* Ghost) 
{
	if ((Ghost->coordFigure()->x == RIGHT_TELEPORT_X) && (Ghost->coordFigure()->y == TELEPORT_Y))
	{
		moveGhost(Ghost, LEFT_TELEPORT_X, TELEPORT_Y);
	}
	else if ((Ghost->coordFigure()->x == LEFT_TELEPORT_X) && (Ghost->coordFigure()->y == TELEPORT_Y))
	{
		moveGhost(Ghost, RIGHT_TELEPORT_X, TELEPORT_Y);;
	}

	if ((level.arrayDecisionPoint[Ghost->coordFigure()->y][Ghost->coordFigure()->x] != nullptr)&&(level.timerEnergizer == 0))
	{
		if (level.arrayDecisionPoint[Ghost->coordFigure()->y][Ghost->coordFigure()->x]->coordFigure()->typeFigure == TypeFigure::DECISIONPOINT)
		{
			m_providinGhost = providingDirection(Ghost);
		}
	}
	else
	{

		if (moveRegulFigure(Ghost->coordFigure()->x, Ghost->coordFigure()->y - 1) && (m_providinGhost != 1))
		{
			m_providinGhost = UP_DIRECTION;
		}
		else if ((moveRegulFigure(Ghost->coordFigure()->x - 1, Ghost->coordFigure()->y)) && (m_providinGhost != 4))
		{
			m_providinGhost = LEFT_DIRECTION;
		}
		else if (moveRegulFigure(Ghost->coordFigure()->x + 1, Ghost->coordFigure()->y) && (m_providinGhost != 3))
		{
			m_providinGhost = RIGHT_DIRECTION;
		}
		else if (moveRegulFigure(Ghost->coordFigure()->x, Ghost->coordFigure()->y + 1) && (m_providinGhost != 2))
		{
			m_providinGhost = DOWN_DIRECTION;
		}
		else m_providinGhost = 0;
	}

	directionGhost(Ghost, m_providinGhost);
}

int Game::providingDirection(Figure* Ghost)
{
	float min[4] = { 100,100,100,100 };
	float m_min = 0;
	int decision = 1;

	if ((moveRegulFigure(Ghost->coordFigure()->x, Ghost->coordFigure()->y + 1)) && (m_providinGhost != 2))
	{
		min[0] = sqrt(pow((Ghost->coordFigure()->x - level.player->coordFigure()->x), 2) + pow(((Ghost->coordFigure()->y + 1) - level.player->coordFigure()->y), 2));
	}
	if ((moveRegulFigure(Ghost->coordFigure()->x, Ghost->coordFigure()->y - 1)) && (m_providinGhost != 1))
	{
		min[1] = sqrt(pow((Ghost->coordFigure()->x  - level.player->coordFigure()->x), 2) + pow(((Ghost->coordFigure()->y - 1) - level.player->coordFigure()->y), 2));
	}
	if ((moveRegulFigure(Ghost->coordFigure()->x - 1, Ghost->coordFigure()->y)) && (m_providinGhost != 4))
	{
		min[2] = sqrt(pow((Ghost->coordFigure()->x - 1  - level.player->coordFigure()->x), 2) + pow(((Ghost->coordFigure()->y) - level.player->coordFigure()->y), 2));
	}
	if ((moveRegulFigure(Ghost->coordFigure()->x + 1, Ghost->coordFigure()->y)) && (m_providinGhost != 3))
	{
		min[3] = sqrt(pow((Ghost->coordFigure()->x + 1 - level.player->coordFigure()->x), 2) + pow(((Ghost->coordFigure()->y ) - level.player->coordFigure()->y), 2));
	}

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

void Game::controlGhost(float deltaTime, Figure* Ghost, double speed) 
{
	if ((level.healthLevel>0)&& (Ghost->coordFigure()->x == level.player->coordFigure()->x) 
	    && (Ghost->coordFigure()->y == level.player->coordFigure()->y) &&(level.timerEnergizer == 0))
	{
		level.healthLevel--;
		controlPlayer(level.startPlayerX, level.startPlayerY);
		Ghost->coordFigure()->earlyX = Ghost->coordFigure()->x = Ghost->coordFigure()->startX;
		Ghost->coordFigure()->earlyY = Ghost->coordFigure()->y = Ghost->coordFigure()->startY;
	} 
	else if ((level.timerEnergizer > 0) && (Ghost->coordFigure()->x == level.player->coordFigure()->x) 
		     && (Ghost->coordFigure()->y == level.player->coordFigure()->y))
	{ 
		level.pointCount +=200;
		Ghost->coordFigure()->earlyX = Ghost->coordFigure()->x = Ghost->coordFigure()->startX;
		Ghost->coordFigure()->earlyY = Ghost->coordFigure()->y = Ghost->coordFigure()->startY;
		controlPlayer(level.player->coordFigure()->x, level.player->coordFigure()->y);
	}

	Ghost->coordFigure()->speed += deltaTime;

	if (Ghost->coordFigure()->speed >= speed)
	{
		controlMoveGhost(Ghost);
		Ghost->coordFigure()->speed = 0;
	}
}

void Game::choiseSymbol(TypeFigure typeFigure, int i, int j)
{
	if (level.timerEnergizer < 1)
	{
		switch (typeFigure)
		{
		case PACMAN:    SetChar(j + 1, i + 1, YELLOW, SYMBOLPACMEN); break;
		case WALL:	    SetChar(j + 1, i + 1, BLUE, SYMBOLWALL);     break;
		case COIN:	    SetChar(j + 1, i + 1, WHITE, SYMBOLCOIN);    break;
		case ENERGIZER: SetChar(j + 1, i + 1, RED, SYMBOLENERGAZER); break;

		case BLINKY:    SetChar(j + 1, i + 1, RED, SYMBOLGHOST);     break;
		case PINKY:     SetChar(j + 1, i + 1, MAGENTA, SYMBOLGHOST); break;
		case INKY:      SetChar(j + 1, i + 1, PURPURE, SYMBOLGHOST); break;
		case CLAYDE:    SetChar(j + 1, i + 1, ORANGE, SYMBOLGHOST);  break;
		default:break;
		}
	}
	else
	{
		switch (level.arrayFigure[i][j]->coordFigure()->typeFigure)
		{
		case PACMAN:    SetChar(j + 1, i + 1, YELLOW, SYMBOLPACMEN); break;
		case WALL:	    SetChar(j + 1, i + 1, BLUE, SYMBOLWALL);     break;
		case COIN:	    SetChar(j + 1, i + 1, WHITE, SYMBOLCOIN);    break;
		case ENERGIZER: SetChar(j + 1, i + 1, RED, SYMBOLENERGAZER); break;

		case BLINKY:    SetChar(j + 1, i + 1, WHITE, SYMBOLGHOST);  break;
		case PINKY:     SetChar(j + 1, i + 1, WHITE, SYMBOLGHOST);  break;
		case INKY:      SetChar(j + 1, i + 1, WHITE, SYMBOLGHOST);  break;
		case CLAYDE:    SetChar(j + 1, i + 1, WHITE, SYMBOLGHOST);  break;
		default:break;
		}
	}
}

void Game::Render()
{
	setLevelConsol(LEVEL_CONSOL_X, LEVEL_CONSOL_Y, level.level);
	setTextConsol(POINT_CONSOL_X, POINT_CONSOL_Y, WHITE, "00000");
	setCountPointConsol(POINT_CONSOL_X, POINT_CONSOL_Y, level.pointCount);
	setHealthLevelConsol(HEARTH_CONSOL_X, HEARTH_CONSOL_Y, level.healthLevel);

	if (level.timerEnergizer > 0)
	{
		setTimerEnergizerConsol(TIMER_CONSOL_X, TIMER_CONSOL_Y, level.timerEnergizer);
	}
	else
	{
		setTextConsol(TIMER_CONSOL_X, TIMER_CONSOL_Y, BLACK, "  ");

	}
	for (int i = 0; i < ARRAY_Y; i++)
	{
		for (int j = 0; j < ARRAY_X; j++)
		{
			if (level.arrayFigure[i][j] == nullptr)
			{
				SetChar(j + 1, i + 1, BLACK, L' ');
			}
			else 
			{
				choiseSymbol(level.arrayFigure[i][j]->coordFigure()->typeFigure, i, j);
			}
		}
	}
}

bool Game::Update(float deltaTime)
 {
	Render();
	sumTimer += deltaTime;
	controlGhost(deltaTime, level.blinky, level.speed );

	if ((sumTimer >= 1)&&(level.timerEnergizer > 0))
	{
		level.timerEnergizer--;
		sumTimer = 0;
	}

	if ((level.healthLevel != 0)&&(level.level < MAX_LEVEL)) return true;
	else return false;
}
