#include "Enemy.h"
#include "Interface.h"

Enemy::Enemy()
{
	rEnemy = rand() % 10 + 1;
	this->hp = 0;
	this->maxHp = 0;
	this->dmg = 0;
	this->critDmg = 0;
	this->name = "none";
}
ForestEnemy::ForestEnemy()
{
	rEnemy = rand() % 3 + 1;
	if (rEnemy == 1)
	{
		this->name = "Wolf";
		this->exp = 50; 
		this->hp = 100; 
		this->maxHp = 100;
		this->dmg = 10; 
		this->critDmg = 20; 
	}
	else if (rEnemy == 2) 
	{ 
		this->exp = 100; 
		this->name = "Brigand";
		this->hp = 150; 
		this->maxHp = 150; 
		this->dmg = 20; 
		this->critDmg = 40; 
	}
	else if (rEnemy == 3) 
	{ 
		this->name = "Slime";
		this->exp = 25; 
		this->hp = 50; 
		this->maxHp = 50; 
		this->dmg = 5; 
		this->critDmg = 15; }
}

Enemy::~Enemy()
{
	cout << "Enemy destructed" << endl;
}

