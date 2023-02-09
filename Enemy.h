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

class Boss :public Enemy
{

public:
	Boss();
};

class ForestBoss : public Boss
{

public:
	ForestBoss();
};