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

class ForestEnemy : public Enemy
{

public:
	ForestEnemy();
};