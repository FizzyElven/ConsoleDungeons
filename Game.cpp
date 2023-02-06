#include "Game.h"

Game::Game()
{
	isPlay = true;
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

void Game::forest(Character* character, Interface *screen)
{
	travel = true;
	forestCounter = 0;
	char a;
	do {
		cout << "You going throw forest..." << endl;
		cout << "Forest counter: " << forestCounter << endl;
		cout << "Select an option:\n1. Move forward\n2. Camp\n3. Return to base" << endl;
		cin >> a;
		switch (a)
		{
		case '1':
		{
			rVal = rand() % 100 + 1;
			if(rVal <=20)
			{
				cout << "Nothing happend..." << endl;
				forestCounter++;
			}
			else if (rVal <= 50)
			{
				cout << "You see the enemy, prepare to battle!"<<endl;
				Enemy* enemy = new Enemy;
				encounter(enemy, character, screen);
				delete enemy;
				forestCounter++;
			}
			else 
			{ 
				forestCounter++; 
			}
			break;
		}
		case '2':
		{
			cout << "You rest the time";
			character->rest();
			break;
		}
		case '3':
		{
			cout << "Returning to base...";
			travel = false;
			break;
		}
		default:
			cout << "invalid choice" << endl;
		}
	} while (travel = true || forestCounter!=30);
	forestBossFight();
}

void Game::encounter(Enemy* enemy, Character *character, Interface *screen)
{
	system("CLS");
	screen->hud(character);
	screen->enemyHud(enemy);
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