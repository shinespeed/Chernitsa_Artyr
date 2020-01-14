#pragma once

#include "BaseApp.h"

class Game : public BaseApp
{
	typedef BaseApp Parent;

	private:

		int addSumFigure;
		float sumTimer;
		float sumTempTimer;
        
		int tempFigureX;
		int tempFigureY;

		int tempX;
		int tempY;

		bool mDirection;

		int providinGhost;

		Figure *temp;

		void Render();

	public:

		Level level;

		Game();

		void controlPlayer(int playerX, int playerY);
		bool moveRegulFigure(int positionX, int positionY);
		void setEatEnergizer();
		void updateLevel();

		void moveGhost(Figure* ghost, int providingDirectiont);
		void controlMoveGhost(Figure* ghost);
		void controlGhost(float deltaTime, Figure* ghost, float speed);
		int providingDirection(Figure* ghost);

		virtual void KeyPressed(int btnCode);
		virtual bool Update(float deltaTime);
};
