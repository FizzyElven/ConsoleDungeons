#include "Locations.h"

Locations::Locations()
{
	this->locationCounter = 0;
	locationName = "none";
}

Locations::Locations(Character* character, Interface* screen, SomeVals* vals)
{
	this->locationCounter = 0;
	locationName = "none";
}

Forest::Forest(Character* character, Interface* screen, SomeVals* vals)
{
	locationName = "forest";
	this->locationCounter = 0;
	journey(character, screen, vals);
	
}

//void Forest::battle(Character* character, Enemy* enemy, Interface* screen)
//{
//
//}
//
//void Forest::BossFight()
//{
//}
//
//void Forest::moveForward(Character* character, Interface* screen, SomeVals* vals)
//{
//}
//
//void Forest::encounter(Enemy* enemy, Character* character, Interface* screen)
//{
//}

void Locations::journey(Character* character, Interface* screen, SomeVals* vals)
{
	{
		char a;
		vals->travel = true;
		do {
			system("CLS");
			screen->hud(character);
			Sleep(1000);
			cout << "You going throw " << locationName <<"..." << endl;
			cout << "Location counter: " << this->locationCounter << endl;
			cout << "Select an option:\n1. Move forward\n2. Camp\n3. Return to base" << endl;
			cin >> a;
			switch (a)
			{
			case '1':
			{
				this->moveForward(character, screen, vals);
				break;
			}
			case '2':
			{
				cout << "You rest the time" << endl;
				Sleep(1000);
				character->rest();
				Sleep(2000);
				break;
			}
			case '3':
			{
				cout << "Returning to base..." << endl;
				Sleep(1000);
				vals->travel = false;
				break;
			}
			default:
				cout << "invalid choice" << endl;
				Sleep(500);
			}
		} while (vals->travel == true && this->locationCounter != 30);
		if (this->locationCounter >= 30)
		{
			BossFight();
		}
	}
}
void Locations::moveForward(Character* character, Interface* screen, SomeVals* vals)
{
	srand(time(NULL));
	vals->rVal = rand() % 100 + 1;
	if (vals->rVal <= 20)
	{
		cout << "Nothing happend..." << endl;
		this->locationCounter++;
		Sleep(1000);
	}
	else if (vals->rVal >=21 && vals->rVal <= 80)
	{
		cout << "You see the enemy, prepare to battle!" << endl;
		Sleep(1000);
		if (locationName == "forest") {
			ForestEnemy* enemy = new ForestEnemy;
			encounter(enemy, character, screen);
			delete enemy;
		}
		else if (locationName == "swamp") {
			ForestEnemy* enemy = new ForestEnemy;
			encounter(enemy, character, screen);
			delete enemy;
		}
		else if (locationName == "dead town") {
			ForestEnemy* enemy = new ForestEnemy;
			encounter(enemy, character, screen);
			delete enemy;
		}
		this->locationCounter++;
	}
	else
	{
		cout << "You find a chest" << endl;
		Sleep(1000);
		this->locationCounter++;
	}
}

void Locations::encounter(Enemy* enemy, Character* character, Interface* screen)
{
	system("CLS");
	BattleSystem *battleWithMonster = new BattleSystem;
	battleWithMonster->battle(character, enemy, screen);
	cout << endl;
	system("pause");
	system("CLS");
	delete battleWithMonster;
}

void Locations::BossFight()
{
}
