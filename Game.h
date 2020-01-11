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

		bool mDirection;

		Figure *temp;

	public:

		Game();

		void controlPlayer(int playerX, int playerY);
		bool moveRegulFigure(int positionX, int positionY);
		void setEatEnergizer();

		virtual void KeyPressed(int btnCode);
		virtual void UpdateF(float deltaTime);
};
