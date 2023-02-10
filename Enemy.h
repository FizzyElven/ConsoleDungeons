#pragma once
#include <iostream>
#include <string>

using namespace std;

class Enemy
{
	
public:
	int rEnemy;
	int maxHp, hp, dmg, critDmg,exp;
	string name;
	Enemy();
	virtual ~Enemy();
};

class ChestEnemy :public Enemy
{
public:
	ChestEnemy();

};

class ForestEnemy : public Enemy
{

public:
	ForestEnemy();
};

class SwampEnemy : public Enemy
{

public:
	SwampEnemy();
};

class DeadTownEnemy : public Enemy
{

public:
	DeadTownEnemy();
};

class ForestBoss : public Enemy
{

public:
	ForestBoss();
};
class SwampBoss : public Enemy
{

public:
	SwampBoss();
};
class DeadTownBoss : public Enemy
{

public:
	DeadTownBoss();
};