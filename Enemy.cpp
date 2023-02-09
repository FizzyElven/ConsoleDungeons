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

SwampEnemy::SwampEnemy()
{
	rEnemy = rand() % 6 + 1;
	if (rEnemy == 1)
	{
		this->name = "Verdurous skeleton";
		this->exp = 100;
		this->hp = 150;
		this->maxHp = 150;
		this->dmg = 20;
		this->critDmg = 30;
	}
	else if (rEnemy == 2)
	{
		this->exp = 150;
		this->name = "Deserter";
		this->hp = 200;
		this->maxHp = 200;
		this->dmg = 30;
		this->critDmg = 60;
	}
	else if (rEnemy == 3)
	{
		this->name = "Deserter-crossbowman";
		this->exp = 125;
		this->hp = 140;
		this->maxHp = 140;
		this->dmg = 40;
		this->critDmg = 100;
	}
	else if (rEnemy == 4)
	{
		this->name = "Verdurous undead";
		this->exp = 150;
		this->hp = 250;
		this->maxHp = 250;
		this->dmg = 20;
		this->critDmg = 35;
	}
	else if (rEnemy == 5)
	{
		this->name = "Lizardman";
		this->exp = 160;
		this->hp = 150;
		this->maxHp = 150;
		this->dmg = 35;
		this->critDmg = 70;
	}
	else if (rEnemy == 6)
	{
		this->name = "Lizardman-archer";
		this->exp = 175;
		this->hp = 120;
		this->maxHp = 120;
		this->dmg = 30;
		this->critDmg = 120;
	}
}
DeadTownEnemy::DeadTownEnemy()
{
	rEnemy = rand() % 10 + 1;
	if (rEnemy == 1)
	{
		this->name = "Skeleton";
		this->exp = 150;
		this->hp = 150;
		this->maxHp = 150;
		this->dmg = 40;
		this->critDmg = 60;
	}
	else if (rEnemy == 2)
	{
		this->exp = 200;
		this->name = "Unded-warrior";
		this->hp = 250;
		this->maxHp = 250;
		this->dmg = 50;
		this->critDmg = 75;
	}
	else if (rEnemy == 3)
	{
		this->name = "Unded-archer";
		this->exp = 200;
		this->hp = 175;
		this->maxHp = 175;
		this->dmg = 55;
		this->critDmg = 150;
	}
	else if (rEnemy == 4)
	{
		this->name = "Unded-crossbowman";
		this->exp = 200;
		this->hp = 200;
		this->maxHp = 250;
		this->dmg = 65;
		this->critDmg = 200;
	}
	else if (rEnemy == 5)
	{
		this->name = "Unded peasant";
		this->exp = 75;
		this->hp = 100;
		this->maxHp = 100;
		this->dmg = 14;
		this->critDmg = 28;
	}
	else if (rEnemy == 6)
	{
		this->name = "Wild dog";
		this->exp = 100;
		this->hp = 125;
		this->maxHp = 125;
		this->dmg = 30;
		this->critDmg = 45;
	}
	else if (rEnemy == 7)
	{
		this->name = "Flesh golem";
		this->exp = 250;
		this->hp = 450;
		this->maxHp = 450;
		this->dmg = 60;
		this->critDmg = 120;
	}
	else if (rEnemy == 8)
	{
		this->name = "Undead knight";
		this->exp = 400;
		this->hp = 400;
		this->maxHp = 400;
		this->dmg = 80;
		this->critDmg = 160;
	}
	else if (rEnemy == 9)
	{
		this->name = "Ghost";
		this->exp = 175;
		this->hp = 175;
		this->maxHp = 175;
		this->dmg = 45;
		this->critDmg = 90;
	}
	else if (rEnemy == 10)
	{
		this->name = "Cultist";
		this->exp = 200;
		this->hp = 200;
		this->maxHp = 200;
		this->dmg = 50;
		this->critDmg = 100;
	}
}

Enemy::~Enemy()
{
	cout << "Enemy was killed" << endl;
}

ForestBoss::ForestBoss()
{
	this->name = "Ogre";
	this->exp = 500;
	this->hp = 500;
	this->maxHp = 500;
	this->dmg = 40;
	this->critDmg = 999;
}

SwampBoss::SwampBoss()
{
	this->name = "Hydra";
	this->exp = 1000;
	this->hp = 800;
	this->maxHp = 800;
	this->dmg = 99;
	this->critDmg = 999;
}

DeadTownBoss::DeadTownBoss()
{
	this->name = "Lich";
	this->exp = 1000;
	this->hp = 1000;
	this->maxHp = 1500;
	this->dmg = 125;
	this->critDmg = 999;
}
