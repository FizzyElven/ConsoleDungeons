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
	bool firstBossKilled;
	bool secondBossKilled;
	bool thirdBossKilled;
	void winGame()
	{
		if (firstBossKilled == true && secondBossKilled == true && thirdBossKilled == true)
		{
			cout << "=====================================" << endl;
			cout << "All bosses defeted! You win the game!" << endl;
			cout << "=====================================" << endl;
			system("pause");
			exit(EXIT_SUCCESS);
		}
	}
	virtual ~Game();

};


