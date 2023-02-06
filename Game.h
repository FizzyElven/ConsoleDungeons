#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>
#include "Character.h"
#include "Weapon.h"
#include "Interface.h"
#include "Enemy.h"
using namespace std;


class Game
{
private:
	int forestCounter;
	int swampCounter;
	int dedTownCounter;
public:
	Game();
	void base(Character *character, Interface* screen);
	bool isPlay;
	virtual ~Game();
	void encounter(Enemy* enemy, Character* character, Interface *screen);
	//Locations functions
	bool travel;
	int rVal;
	void forest(Character* character, Interface *screen);
	void forestBossFight();
	void swamp();
	void deadTown();
};


