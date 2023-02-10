#include "Locations.h"

Locations::Locations()
{
	this->locationCounter = 0;
	neededLocCounter = 0;
	bossDefeated = false;
	locationName = "none";
}

Locations::Locations(Character* character, Interface* screen, SomeVals* vals)
{
	this->locationCounter = 0;
	neededLocCounter = 0;
	bossDefeated = false;
	locationName = "none";
}

void Locations::beforeBossfight(Character* character)
{
	cout << "You rest before the bossfight..." << endl;
	character->setHp(character->getMaxHp());
	character->setStamina(character->getMaxStamina());
	character->setMana(character->getMaxMp());
	character->setArrows(character->getMaxArrows());
	Sleep(1000);
}

Forest::Forest(Character* character, Interface* screen, SomeVals* vals)
{
	locationName = "forest";
	bossDefeated = false;
	this->locationCounter = 0;
	neededLocCounter = 30;
	journey(character, screen, vals);
	
}
Swamp::Swamp(Character* character, Interface* screen, SomeVals* vals)
{
	locationName = "swamp";
	bossDefeated = false;
	this->locationCounter = 0;
	neededLocCounter = 50;
	journey(character, screen, vals);

}
DeadTown::DeadTown(Character* character, Interface* screen, SomeVals* vals)
{
	locationName = "dead town";
	bossDefeated = false;
	this->locationCounter = 0;
	neededLocCounter = 75;
	journey(character, screen, vals);

}

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
		} while (vals->travel == true && this->locationCounter != this->neededLocCounter);
		if (this->locationCounter >= this->neededLocCounter)
		{
			beforeBossfight(character);
			bossFight(character, screen);
		}
	}
}

void Locations::moveForward(Character* character, Interface* screen, SomeVals* vals)
{
	srand(time(NULL));
	vals->rVal = rand() % 100 + 1;
	if (vals->rVal <= 30)
	{
		cout << "Nothing happend..." << endl;
		this->locationCounter++;
		Sleep(1000);
	}
	else if (vals->rVal >=31 && vals->rVal <= 80)
	{
		meetMonster(character, screen);
	}
	else
	{
		cout << "You find a chest" << endl;
		chest(character, screen);
		this->locationCounter++;
		Sleep(1000);
		
	}
}

void Locations::meetMonster(Character* character, Interface* screen)
{
	cout << "You see the enemy, prepare to battle!" << endl;
	Sleep(1000);
	if (locationName == "forest") {
		ForestEnemy* enemy = new ForestEnemy;
		encounter(enemy, character, screen);
		delete enemy;
	}
	else if (locationName == "swamp") {
		SwampEnemy* enemy = new SwampEnemy;
		encounter(enemy, character, screen);
		delete enemy;
	}
	else if (locationName == "dead town") {
		DeadTownEnemy* enemy = new DeadTownEnemy;
		encounter(enemy, character, screen);
		delete enemy;
	}
	this->locationCounter++;
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

void Locations::chest(Character* character, Interface* screen)
{
	char chestChoice;
	do {
		cout << "1. Open the chest\n2. Go away" << endl;
		cin >> chestChoice;
		switch (chestChoice)
		{
			case '1':
			{
				int k = rand() % 12 + 1;
				if (k == 12)
				{
					cout << "This chest is a mimic!" << endl;
					Sleep(1000);
					ChestEnemy* mimic = new ChestEnemy;
					encounter(mimic, character, screen);
				}
				else if (k <= 3)
				{
					cout << "Chest is empty" << endl;
					Sleep(1000);
				}
				else if (k <= 5)
				{
					cout << "You find healing potion and heal " <<character->getMaxHp()-character->getHp() << "hp" << endl;
					character->heal(character->getMaxHp() - character->getHp());
					Sleep(1000);
				}
				else if (k <= 7)
				{
					cout << "You find material for upgrade your weapon." << endl;
					cout << "Your damage has been increased by 5" << endl;
					character->dmg += 5;
					Sleep(1000);
				}
				else if (k <= 9)
				{
					cout << "You find material for upgrade your armor." << endl;
					cout << "Your defence has been increased by 2" << endl;
					character->defence += 2;
					Sleep(1000);
				}
				else if (k <= 11)
				{
					cout << "The chest turned out to be empty, besides, you understand that you were ambushed" << endl;
					Sleep(1000);
					meetMonster(character, screen);
				};
				break;
			}
			case '2':
			{
				cout << "You decide not to open the chest and move on" << endl;
				Sleep(1000);
			}
			default:
			{
				cout << "Invalid choice" << endl;
				Sleep(1000);
			}
		}
	} while (chestChoice != '1' && chestChoice != '2');
}

void Locations::bossFight(Character* character, Interface* screen)
{
	cout << "Location completed, now you need to defeat boss" << endl;
	Sleep(1000);
	system("pause");
	if (locationName == "forest") {
		ForestBoss* boss = new ForestBoss;
		encounter(boss, character, screen);
		bossDefeated = true;
		cout << "You kill first of 3 bosses needed!" << endl;
		Sleep(1000);
		system("pause");
		delete boss;
	}
	else if (locationName == "swamp") {
		SwampBoss* enemy = new SwampBoss;
		encounter(enemy, character, screen);
		bossDefeated = true;
		cout << "You kill second of 3 bosses needed!" << endl;
		Sleep(1000);
		system("pause");
		delete enemy;
	}
	else if (locationName == "dead town") {
		DeadTownBoss* enemy = new DeadTownBoss;
		encounter(enemy, character, screen);
		bossDefeated = true;
		cout << "You kill third of 3 bosses needed!" << endl;
		Sleep(1000);
		system("pause");
		delete enemy;
	}
}
