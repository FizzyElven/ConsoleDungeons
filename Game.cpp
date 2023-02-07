#include "Game.h"

Game::Game()
{
	isPlay = true;
}

Game::~Game()
{

}

void Game::base(Character *character, Interface *screen, SomeVals *vals)
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
			Forest *forest = new Forest(character, screen, vals);
			//forest(character, screen);
			break;
		}
		case '2':
		{
			;
			break;
		}
		case '3':
		{
			;
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

