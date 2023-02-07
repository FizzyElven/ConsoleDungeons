#include "BattleSystem.h"

BattleSystem::BattleSystem()
{
	combat = false;
}

BattleSystem::~BattleSystem()
{
}

void BattleSystem::battle(Character* character, Enemy* enemy, Interface* screen)
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
							cout << "You deal " << character->dmg << " damage" << endl;
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
							cout << "You deal " << character->dmg * 2 << " damage" << endl;
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
							cout << "You deal " << character->dmg << " damage" << endl;
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
							cout << "You deal " << character->dmg * 3 << " damage" << endl;
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
				cout << "Choose spell:\n1. Fireball (10mp&st)\n2. Lightning bolt (25mp&st)\n3. Heal (25mp&st)" << endl;
				cin >> j;
				switch (j)
				{
				case '1':
				{
					if (character->getStamina() >= 10 && character->getMp() >= 10)
					{
						enemy->hp -= character->dmg;
						character->setStamina(character->getStamina() - 10);
						character->setMana(character->getMp() - 10);
						cout << "You deal " << character->dmg << " damage" << endl;
						Sleep(1000);
					}
					else {
						cout << "Not enoght stamina or arrows" << endl; Sleep(1000);
					}
					break;
				}
				case '2':
				{
					if (character->getStamina() >= 25 && character->getMp() >= 25)
					{
						enemy->hp -= character->dmg * 3;
						character->setStamina(character->getStamina() - 20);
						character->setMana(character->getMp() - 20);
						cout << "You deal " << character->dmg * 3 << " damage" << endl;
						Sleep(1000);
					}
					else {
						cout << "Not enoght stamina or arrows" << endl; Sleep(1000);
					}
					break;
				}
				case '3':
				{
					if (character->getStamina() >= 25 && character->getMp() >= 25)
					{
						if (character->getHp() <= character->getMaxHp() - 25)
						{
							cout << "You have restored 25hp" << endl;
							character->heal(25);
						}
						else
						{
							cout << "You have restored " << (character->getMaxHp() - character->getHp()) << "hp" << endl;
							character->heal(character->getMaxHp() - character->getHp());
						}
						character->setStamina(character->getStamina() - 25);
						character->setMana(character->getMp() - 25);
						Sleep(1000);
					}
					else {
						cout << "Not enoght stamina or mp" << endl; Sleep(1000);
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
		//Stamina restoration
		if (character->getStamina() <= character->getMaxStamina() - 5)
		{
			character->setStamina(character->getStamina() + 5);
		}
		else character->setStamina(character->getMaxStamina());
		//Mana restoration
		if (character->getClass() == "mage") {
			if (character->getMp() <= character->getMaxMp() - 5)
			{
				character->setMana(character->getMp() + 5);
			}
			else character->setMana(character->getMaxMp());
		}
		//Check enemy die
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