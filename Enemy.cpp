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
	if (rEnemy == 1) 
	{ 
		this->hp = 100; this->maxHp = 100; this->dmg = 10; this->critDmg = 20; this->name = "Wolf";
	}
	else { this->name = "Brigand"; this->hp = 150; this->maxHp = 150; this->dmg = 20; this->critDmg = 40; }
}

Enemy::~Enemy()
{
	cout << "Enemy destructed" << endl;
}

void Enemy::battle()
{
	
}
