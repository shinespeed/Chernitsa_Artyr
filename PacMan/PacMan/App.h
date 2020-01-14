#pragma once

#include "BaseApp.h"
#include "Game.h"

enum MenuOption
{
	NEWGAME,
	EXITGAME
};

class App : public BaseApp
{
	typedef BaseApp Parent;

private:

	bool mDirection;

	void Render();
	void Menu();

	int menuX;
	int menuY;

	int idMenu;
	MenuOption menuOption;

	bool gameOver;

	Game* game;

public:

	App();

	virtual void KeyPressed(int btnCode);
	virtual bool Update(float deltaTime);
};

