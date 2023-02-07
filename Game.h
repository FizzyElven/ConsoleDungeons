#pragma once
#include <iostream>
#include <ctime>
#include <conio.h>
#include "Character.h"
#include "Interface.h"
#include "Enemy.h"
#include "Locations.h"
using namespace std;


class Game
{
private:
	
public:
	Game();
	void base(Character *character, Interface* screen, SomeVals* vals);
	bool isPlay;
	virtual ~Game();

};


