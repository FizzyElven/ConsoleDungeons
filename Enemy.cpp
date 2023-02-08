#include "Enemy.h"

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
	rEnemy = rand() % 5 + 1;
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
	else if (rEnemy == 4)
	{
		this->name = "Bear";
		this->exp = 125;
		this->hp = 250;
		this->maxHp = 250;
		this->dmg = 24;
		this->critDmg = 48;
	}
	else if (rEnemy == 5)
	{
		this->name = "Goblin";
		this->exp = 75;
		this->hp = 125;
		this->maxHp = 125;
		this->dmg = 16;
		this->critDmg = 40;
	}
}
ChestEnemy::ChestEnemy()
{
	this->name = "Mimic";
	this->exp = 200;
	this->hp = 200;
	this->maxHp = 200;
	this->dmg = 50;
	this->critDmg = 75;
}

Enemy::~Enemy()
{
	cout << "Enemy destructed" << endl;
}

