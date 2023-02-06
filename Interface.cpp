#include "Interface.h"

void Interface::hud(Character* character)
{
	// Draws top border
	cout << "====================";
	cout << endl;
	//STATS
	cout << "| Name: " << character->getName() << endl;
	cout << "| Class: " << character->getClass() << endl;
	cout << "| HP: " << character->getHp() << "/" << character->getMaxHp() << endl;
	cout << "| Level: " << character->getLevel() << endl;
	cout << "| XP: " << character->getXp() << "/" << character->getXpToUp() << endl;
	cout << "| Stamina: " << character->getStamina() << "/" << character->getMaxStamina() << endl;
	cout << "| Dmg: " << character->dmg << endl;
	cout << "| Defence: " << character->defence << endl;
	if (character->getClass() == "mage") {
		cout << "| Mana: " << character->getMp() << "/" << character->getMaxMp() << endl;
		for (int i = 1; i < 10; i++)
		{
			setcur(18, i);
			cout << " |";
		}
	}
	else if (character->getClass() == "archer") {
		cout << "| Arrows: " << character->getArrows() << "/" << character->getMaxArrows() << endl;
		for (int i = 1; i < 10; i++)
		{
			setcur(18, i);
			cout << " |";
		}
	}
	else {
		cout << "WE" << endl;
		for (int i = 1; i < 9; i++)
		{
			setcur(18, i);
			cout << " |";
		}
	}
	cout << endl;
	// Draws bottom border
	cout << "====================";
	cout << endl;
}

void Interface::enemyHud(Enemy* enemy)
{
	// Draws top border
	setcur(25, 0);
	cout << "====================";
	cout << endl;
	//STATS
	setcur(25, 1);
	cout << "| Name: " << enemy->name << endl;
	setcur(25, 2);
	cout << "| HP: " << enemy->hp<< "/" << enemy->maxHp << endl;
	for (int i = 1; i < 3; i++)
	{
		setcur(43, i);
		cout << " |";
	}
	cout << endl;
	// Draws bottom border
	setcur(25, 3);
	cout << "====================";
	cout << endl;
	setcur(0, 10);
}