#include "Game.h"

using namespace std;

void color(int color);

int main()
 {
	srand(time(NULL));
	Game game;
	Character player;
	Interface screen;
	SomeVals vals;
	color(3);
	//START GAME//
	cout << "======CONSOLE DUNGEONS======" << endl << endl;
	//Character creation//
	player.selectClass();
	cout << "Your character class is: " << player.getClass() << endl;
	system("pause");
	system("CLS");

	player.setName();
	cout << "Your character name is: ";
	cout << player.getName() << endl;
	system("pause");
	system("CLS");
	
	while (game.isPlay) 
	{
	system("CLS"); 
	screen.hud(&player);
	game.base(&player, &screen, &vals);
	Sleep(1000);
	}
}
void color(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}



