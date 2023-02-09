#pragma once

#include <conio.h>
#include "BattleSystem.h"
using namespace std;

class Locations
{
private:
	
public:
	Locations();
	Locations(Character* character, Interface* screen, SomeVals* vals);
	int locationCounter;
	string locationName;
	bool bossDefeated;
	void bossFight(Character* character, Interface* screen);
	void moveForward(Character* character, Interface* screen, SomeVals* vals);
	void encounter(Enemy* enemy, Character* character, Interface* screen);
	void chest(Character* character, Interface* screen);
	void journey(Character* character, Interface* screen, SomeVals* vals);
	void meetMonster(Character* character, Interface* screen);
};

class Forest :public Locations
{
private:
	
public:
	Forest(Character* character, Interface* screen, SomeVals* vals);
	
};