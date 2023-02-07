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
	void battle(Character* character, Enemy* enemy, Interface* screen);
	void BossFight();
	void moveForward(Character* character, Interface* screen, SomeVals* vals);
	void encounter(Enemy* enemy, Character* character, Interface* screen);
	
	void journey(Character* character, Interface* screen, SomeVals* vals);
};

class Forest :public Locations
{
private:
	
public:
	Forest(Character* character, Interface* screen, SomeVals* vals);
	/*void battle(Character* character, Enemy* enemy, Interface* screen);
	void BossFight();
	void moveForward(Character* character, Interface* screen, SomeVals* vals) ;
	void encounter(Enemy* enemy, Character* character, Interface* screen) ;*/

};