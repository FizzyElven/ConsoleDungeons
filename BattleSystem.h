#pragma once
#include "Character.h"
#include "Interface.h"
#include "Enemy.h"
#include "SomeVals.h"

class BattleSystem
{
private:

public:
	bool combat;
	BattleSystem();
	virtual ~BattleSystem();
	void battle(Character* character, Enemy* enemy, Interface* screen);
	void battleMenu(Character* character, Enemy* enemy, Interface* screen);
	void warriorAttack(Character* character, Enemy* enemy);
	void archerAttack(Character* character, Enemy* enemy);
	void mageAttack(Character* character, Enemy* enemy, Interface* screen);
};

