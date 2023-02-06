#include "Game.h"

Game::Game()
{
	isPlay = true;
	combat = false;
	rVal = 0;
	travel = true;
	forestCounter=0;
	swampCounter=0;
	dedTownCounter = 0;
}

Game::~Game()
{

}

void Game::base(Character *character, Interface *screen)
{
	char choice;
	do {
		cout << "You on base now" << endl;
		cout << "1. Go to forest" << endl;
		cout << "2. Go to swamp" << endl;
		cout << "3. Go to dead town" << endl;
		cout << "4. Rest" << endl;
		cout << "5. Surrender and exit game" << endl;
		cin >> choice;
		switch (choice) {
		case '1':
		{
			forest(character, screen);
			break;
		}
		case '2':
		{
			swamp();
			break;
		}
		case '3':
		{
			deadTown();
			break;
		}
		case '4':
		{
			character->rest();
			break;
		}
		case '5':
		{
			isPlay=false;
			break;
		}
		default:
			cout << "invalid choice.";
			break;
		}

	} while (choice != '1' && choice != '2' && choice != '3' && choice != '4' && choice != '5');
}

void Game::forest(Character* character, Interface* screen)
{
	forestCounter = 0;
	char a;
	do {
		system("CLS");
		screen->hud(character);
		Sleep(1000);
		cout << "You going throw forest..." << endl;
		cout << "Forest counter: " << forestCounter << endl;
		cout << "Select an option:\n1. Move forward\n2. Camp\n3. Return to base" << endl;
		cin >> a;
		switch (a)
		{
		case '1':
		{
			rVal = rand() % 100 + 1;
			if (rVal <= 20)
			{
				cout << "Nothing happend..." << endl;
				forestCounter++;
				Sleep(1000);
			}
			else if (rVal <= 80)
			{
				cout << "You see the enemy, prepare to battle!" << endl;
				Sleep(1000);
				ForestEnemy* enemy = new ForestEnemy;
				encounter(enemy, character, screen);
				delete enemy;
				forestCounter++;
			}
			else
			{
				cout << "You find a chest" << endl;
				Sleep(1000);
				forestCounter++;
			}
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
			travel = false;
			break;
		}
		default:
			cout << "invalid choice" << endl;
			Sleep(500);
		}
	} while (travel == true && forestCounter != 30);
	if (forestCounter >= 30)
	{
		forestBossFight();
	}
}

void Game::encounter(Enemy* enemy, Character *character, Interface *screen)
{
	system("CLS");
	battle(character, enemy, screen);
	system("pause");
	system("CLS");
}

void Game::battle(Character* character, Enemy* enemy, Interface* screen)
{
	char i;
	char j;
	char k;
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
					else { cout << "Not enoght stamina" << endl; Sleep(1000);
					}
					break;
				}
				case '2':
				{
					if (character->getStamina() >= 20)
					{
						enemy->hp -= character->dmg*2;
						character->setStamina(character->getStamina() - 20);
						Sleep(1000);
					}
					else { cout << "Not enoght stamina" << endl; Sleep(1000);
					}
					break;
				}
				}
				
			}
			else if (character->getClass() == "archer")
			{
				cout << "Choose attack type:\n1. Single shot (5st)\n2. Triple shot (15st)" << endl;
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
					else { cout << "Not enoght stamina or arrows" << endl; Sleep(1000);
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
					else { cout << "Not enoght stamina or arrows" << endl; Sleep(1000);
					}
					break;
				}
				}
				
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
			break;
		}
		}
		if (enemy->hp > 0)
		{
			if (i == '2') { character->setHp(character->getHp() - ((character->defence*2) - enemy->dmg)); }
			else 
			{
				character->setHp(character->getHp() - (character->defence - enemy->dmg));
			}
		}
		if (character->getStamina() <= character->getMaxStamina() - 5) 
		{
			character->setStamina(character->getStamina() + 5);
		}
		else character->setStamina(character->getMaxStamina() - character->getStamina());
		
		if (enemy->hp <= 0) 
		{ 
			system("CLS");
			screen->hud(character);
			screen->enemyHud(enemy);
			Sleep(1000);
			character->setXp(character->getXp()+enemy->exp); 
			if (character->getXp() >= character->getXpToUp())
			{
				character->overXp = character->getXp()-character->getXpToUp(); 
				character->setLevel(character->getLevel() + 1);
				character->setXp(character->getXp() + character->overXp);
			}

		combat = false; 
		}
	}while(combat != false);
}

void Game::swamp()
{
	swampCounter = 0;
}

void Game::forestBossFight()
{
}

void Game::deadTown()
{
	dedTownCounter = 0;
}