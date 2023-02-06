#pragma once
#include <iostream>
#include <string>
using namespace std;

class Enemy
{
	
public:
	int rEnemy;
	int maxHp, hp, dmg, critDmg;
	string name;
	Enemy();
	virtual ~Enemy();
	void battle();
};

