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

	int m_Ghost;
	int idMenu;
	bool gameOver;

    MenuOption menuOption;
	Game* game;

	void Render();
	void generationBonorderMenu();
	void newGame();
};

#endif