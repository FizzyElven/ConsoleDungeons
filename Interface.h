#pragma once
#include "Character.h"
#include "Enemy.h"

class Interface
{
private:

public:
	void hud(Character* character);
	void enemyHud(Enemy* enemy);
	void setcur(int x, int y)//установка курсора на позицию  x y 
	{
		COORD coord{};
		coord.X = x;
		coord.Y = y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	};
};
