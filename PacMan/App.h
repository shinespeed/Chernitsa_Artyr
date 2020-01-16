#ifndef APP_H
#define APP_H

#include "BaseApp.h"
#include "Game.h"

enum MenuOption
{
	NEWGAME,
	EXITGAME
};

class App: public BaseApp
{
public:
	App();

	void KeyPressed(int btnCode);
	bool Update(float deltaTime);

private:

	bool mDirection;

	void Render();

	int menuX;
	int menuY;
	int m_Ghost;
	int idMenu;

	MenuOption menuOption;

	bool gameOver;

	Game* game;
};

#endif