#pragma once

#include <conio.h>
#include "Character.h"
#include "Interface.h"
#include "Enemy.h"
#include "SomeVals.h"
using namespace std;

class Locations
{
private:
	
public:
	Locations();
	Locations(Character* character, Interface* screen, SomeVals* vals);
	int locationCounter;
	string locationName;
	bool combat;
	virtual void battle(Character* character, Enemy* enemy, Interface* screen);
	virtual void BossFight();
	virtual void moveForward(Character* character, Interface* screen, SomeVals* vals);
	virtual void encounter(Enemy* enemy, Character* character, Interface* screen);
	
	virtual void journey(Character* character, Interface* screen, SomeVals* vals);
};

class Forest :public Locations
{
private:
	
public:
	Forest(Character* character, Interface* screen, SomeVals* vals);
	void battle(Character* character, Enemy* enemy, Interface* screen) override;
	void BossFight() override;
	void moveForward(Character* character, Interface* screen, SomeVals* vals) override;
	void encounter(Enemy* enemy, Character* character, Interface* screen) override;

};