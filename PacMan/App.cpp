#include "App.h"

App::App():
	BaseApp(X_SIZE, Y_SIZE),
	mDirection(true),
	menuOption(MenuOption::NEWGAME),
	idMenu(0),
	gameOver(false),
	m_Ghost(0)
{}

void App::KeyPressed(int btnCode)
{
	switch (btnCode)
	{
	case UP:
		if (idMenu > 0) idMenu--;
		break;
	case DOWN:
		if (idMenu < 1) idMenu++;
		break;
	case ENTER:
		menuOption = (MenuOption)idMenu;
		if (menuOption == NEWGAME) 
		{
			newGame();
		}
		break;

	default:break;
	}
}

void App::newGame() 
{
	gameOver = false;
	game = new Game();
	game->Run();
}

void App::BonorderMenu(int i, int j) 
{
	if ((i == 0) || (j == 0) || (i == MENU_ARRAY_BORDER_X - 1) || (j == MENU_ARRAY_BORDER_Y - 1))
	{
		SetChar(i + MENU_CONSOL_BORDER_X, j + MENU_CONSOL_BORDER_Y, WHITE, SYMBOLBORDER);
	}
}

void App::generationBonorderMenu()
{
	for (int i = 0; i < MENU_ARRAY_BORDER_X; ++i)
	{
		for (int j = 0; j < MENU_ARRAY_BORDER_Y; ++j)
		{
			BonorderMenu(i, j);
		}
	}
}

void App::Render()
{
	generationBonorderMenu();

	if (idMenu == 0)
	{
		setTextConsol(MENUNEWGAMES_X, MENUNEWGAMES_Y, RED,  "NEW GAME   <");
	}
	else
	{
		setTextConsol(MENUNEWGAMES_X, MENUNEWGAMES_Y, WHITE, "NEW GAME    ");
	}

	if (idMenu == 1)
	{
		setTextConsol(MENUNEXIT_X, MENUNEXIT_Y, RED, "EXIT GAME  <");
	} 
	else
	{
		setTextConsol(MENUNEXIT_X, MENUNEXIT_Y, WHITE, "EXIT GAME   ");
	}

	if (true == gameOver)
	{
		setTextConsol(X_STRING_GAMEOVER, Y_STRING_GAMEOVER, RED, "GAME OVER");
		setTextConsol(X_STRING_YOUPOINT, Y_STRING_YOUPOINT, RED, "YOU POINT: ");
		setCountPointConsol(MENU_POINT_X, MENU_POINT_Y, m_Ghost);
	}
}

bool App::Update(float deltaTime)
{
	Render();

	if (nullptr != game)
	{
		if (game->level.healthLevel == 0)
		{
			gameOver = true;
			m_Ghost = game->level.pointCount;
		}
	}
	else if ((nullptr != game) && (true == gameOver))
	{
		delete game;
	}

	if (menuOption != EXITGAME) return true;
	else return false;
}

