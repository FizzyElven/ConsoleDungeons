#include "Game.h"

Game::Game()
{
	isPlay = true;
	firstBossKilled = false;
	secondBossKilled = false;
	thirdBossKilled = false;
}

Game::~Game()
{

}

void Game::base(Character *character, Interface *screen, SomeVals *vals)
{
	char choice;
	do {
		cout << "You on base now" << endl;
		cout << "1. Go to forest (recommended lvl 1-5)" << endl;
		cout << "2. Go to swamp (recommended lvl 5-10)" << endl;
		cout << "3. Go to dead town (recommended lvl 10-15)" << endl;
		cout << "4. Rest" << endl;
		cout << "5. Surrender and exit game" << endl;
		cin >> choice;
		switch (choice) {
		case '1':
		{
			Forest *forest = new Forest(character, screen, vals);
			if (forest->bossDefeated == true) { firstBossKilled = true; }
			delete forest;
			break;
		}
		case '2':
		{
			Swamp* swamp = new Swamp(character, screen, vals);
			if (swamp->bossDefeated == true) { secondBossKilled = true; }
			delete swamp;
			break;
		}
		case '3':
		{
			DeadTown* deadTown = new DeadTown(character, screen, vals);
			if (deadTown->bossDefeated == true) { thirdBossKilled = true; }
			delete deadTown;
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

