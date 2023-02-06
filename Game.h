#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>
#include "Character.h"
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
	bool combat;
	virtual ~Game();
	void encounter(Enemy* enemy, Character* character, Interface *screen);
	//Locations functions
	bool travel;
	int rVal;
	void battle(Character* character, Enemy* enemy, Interface* screen);
	void forest(Character* character, Interface *screen);
	void forestBossFight();
	void swamp();
	void deadTown();
};


