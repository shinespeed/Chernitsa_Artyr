#ifndef GAME_H
#define GAME_H

#include "Level.h"
#include "BaseApp.h"

class Game: public BaseApp
{
public:
	Game();
	~Game();

	Level level;

	void controlPlayer(int playerX, int playerY);
	bool moveRegulFigure(int positionX, int positionY);
	void updateLevel();

	void moveGhost(Figure* Ghost, int x, int y);
	void directionGhost(Figure* Ghost, int providingDirectiont);
	void controlMoveGhost(Figure* Ghost);
	void controlGhost(float deltaTime, Figure* Ghost, double speed);

	int providingDirection(Figure* Ghost);

	void KeyPressed(int btnCode);
	bool Update(float deltaTime);

private:
	int addSumFigure;
	float sumTimer;  
	int m_rand;
	bool mDirection;
	int m_providinGhost;
	Figure* m_temp;

	void Render();
};

#endif
