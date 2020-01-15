#pragma once

#include "BaseApp.h"

class Game : public BaseApp
{
	typedef BaseApp Parent;

	private:

		int addSumFigure;
		float sumTimer;
     

		bool mDirection;

		int providinGhost;

		Figure *temp;

		void Render();

	public:

		Level level;

		Game();

		void controlPlayer(int playerX, int playerY);
		bool moveRegulFigure(int positionX, int positionY);
		void updateLevel();

		void moveGhost(Figure* ghost, int x, int y);
		void directionGhost(Figure* ghost, int providingDirectiont);
		void controlMoveGhost(Figure* ghost);
		void controlGhost(float deltaTime, Figure* ghost, double speed);

		int providingDirection(Figure* ghost);

		virtual void KeyPressed(int btnCode);
		virtual bool Update(float deltaTime);
};
