#include "App.h"

App::App(): Parent(42, 21)
{
	mDirection = true;
	menuOption = MenuOption::NEWGAME; 
	menuY = 6;
	menuX = 12;
	idMenu = 0;
	gameOver = false;
}

void App::KeyPressed(int btnCode)
{
	switch (btnCode)
	{
	case 119:
		if (idMenu > 0) idMenu--;
			break;
	case 115:
		if (idMenu < 1) idMenu++;
		break;
	case 13:
		menuOption = (MenuOption)idMenu;
		if (menuOption == NEWGAME) 
		{
			delete game;
			game = new Game();
			game->Run();
			gameOver = true;
		}
		break;
	}

}

void App::Render()
{
	string str = { "NEW GAME" };
	if (idMenu == 0)
	{
		setTextConsol(menuX + 15, menuY + 3, 4,  "NEW GAME  <");
	} else	setTextConsol(menuX + 15, menuY + 3, 7, str + "   ");

	str = { "EXIT GAME" };

	if (idMenu == 1)
	{
		setTextConsol(menuX + 15, menuY + 5, 4, "EXIT GAME <");
	} else  setTextConsol(menuX + 15, menuY + 5, 7, str + "  ");

	for (int i = 0; i < 20; i++) 
      for(int j = 0; j < 9; j++)
	  {
		  if ((i == 0)||(j == 0)||(i == 19)||(j == 8)) SetChar(i+menuX, j+menuY, 7, 178);
	  }

	if (gameOver) 
	
	{
		setTextConsol(menuX + 15, menuY - 4, 4, "GAME OVER");
		setTextConsol(menuX + 12, menuY - 2, 4, "YOU POINT:");
		setCountPointConsol(menuX + 18, menuY - 2, game->level.pointPlayer);
	}
}

void App::Menu() 
{

}

bool App::Update(float deltaTime)
{
	Render();
	if (menuOption != EXITGAME) return TRUE;
	else return FALSE;
}

