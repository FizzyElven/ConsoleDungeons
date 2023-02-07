#include "Locations.h"

Locations::Locations()
{
	this->locationCounter = 0;
	combat = false;
	locationName = "none";
}

Locations::Locations(Character* character, Interface* screen, SomeVals* vals)
{
	this->locationCounter = 0;
	combat = false;
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
				cout << "You rest the time";
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
	vals->rVal = rand() % 100 + 1;
	if (vals->rVal <= 20)
	{
		cout << "Nothing happend..." << endl;
		this->locationCounter++;
		Sleep(1000);
	}
	else if (vals->rVal <= 80)
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
	battle(character, enemy, screen);
	cout << endl;
	system("pause");
	system("CLS");
}

void Locations::battle(Character* character, Enemy* enemy, Interface* screen)
{
	char i;
	char j;
	//char k;
	combat = true;
	do {
		system("CLS");
		screen->hud(character);
		screen->enemyHud(enemy);
		Sleep(1000);
		cout << "\nBattle menu:\n1. Attack\n2. Defend\n3. Use item" << endl;
		cin >> i;
		switch (i)
		{
		case '1':
		{
			if (character->getClass() == "warrior")
			{
				cout << "Choose attack type:\n1. Light attack (10st)\n2. Power attack(20st)" << endl;
				do {
					cin >> j;
					switch (j)
					{
					case '1':
					{
						if (character->getStamina() >= 10)
						{
							enemy->hp -= character->dmg;
							character->setStamina(character->getStamina() - 10);
							Sleep(1000);
						}
						else {
							cout << "Not enoght stamina" << endl; Sleep(1000);
						}
						break;
					}
					case '2':
					{
						if (character->getStamina() >= 20)
						{
							enemy->hp -= character->dmg * 2;
							character->setStamina(character->getStamina() - 20);
							Sleep(1000);
						}
						else {
							cout << "Not enoght stamina" << endl; Sleep(1000);
						}
						break;
					}
					default:
					{cout << "Invalid choice" << endl; Sleep(1000); break; }
					}
				} while (j != '1' && j != '2');
			}
			else if (character->getClass() == "archer")
			{
				cout << "Choose attack type:\n1. Single shot (5st)\n2. Triple shot (15st)" << endl;
				do {
					cin >> j;
					switch (j)
					{
					case '1':
					{
						if (character->getStamina() >= 5 && character->getArrows() >= 1)
						{
							enemy->hp -= character->dmg;
							character->setStamina(character->getStamina() - 5);
							character->setArrows(character->getArrows() - 1);
							Sleep(1000);
						}
						else {
							cout << "Not enoght stamina or arrows" << endl; Sleep(1000);
						}
						break;
					}
					case '2':
					{
						if (character->getStamina() >= 15 && character->getArrows() >= 3)
						{
							enemy->hp -= character->dmg * 3;
							character->setStamina(character->getStamina() - 15);
							character->setArrows(character->getArrows() - 3);
							Sleep(1000);
						}
						else {
							cout << "Not enoght stamina or arrows" << endl; Sleep(1000);
						}
						break;
					}
					default:
					{
						cout << "Invalid choice" << endl;
						Sleep(1000);
						break;
					}

					}
				} while (j != '1' && j != '2');
			}
			else if (character->getClass() == "mage")
			{
				cout << "Choose spell:\n1. Fireball (10mp)\n2. Lightning bolt (20mp)\n3. Heal (25mp)" << endl;
				cin >> j;
			}
			break;
		}
		case '2':
		{
			cout << "Your defence incresed by 10" << endl;
			Sleep(1000);
			break;
		}
		case '3':
		{
			cout << "item menu" << endl;
			Sleep(1000);
			break;
		}
		default: {cout << "Invalid choice" << endl; break; }
		}
		if (enemy->hp > 0)
		{
			if (i == '2')
			{
				if ((character->defence + 10) >= enemy->dmg)
				{
					cout << "Your defense absorbed all the damage" << endl;
					Sleep(1000);
				}
				else
				{
					character->setHp(character->getHp() - (enemy->dmg - (character->defence + 10)));
				}
			}
			else
			{
				if ((character->defence) >= (enemy->dmg))
				{
					cout << "Your defense absorbed all the damage" << endl;
					Sleep(1000);
				}
				else
				{
					character->setHp(character->getHp() - (enemy->dmg - character->defence));
				}
			}
		}

		if (character->getStamina() <= character->getMaxStamina() - 5)
		{
			character->setStamina(character->getStamina() + 5);
		}
		else character->setStamina(character->getMaxStamina());

		if (enemy->hp <= 0)
		{
			system("CLS");
			screen->hud(character);
			screen->enemyHud(enemy);
			Sleep(1000);
			character->setXp(character->getXp() + enemy->exp);
			character->lvlup();

			combat = false;
		}
	} while (combat != false);
}

void Locations::BossFight()
{
}
