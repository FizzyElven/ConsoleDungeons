#include "Character.h"

Character::Character()
{
	this->name = "noname";
	this->Class = "noclass";
	this->level = 1;
	this->hp = 0;
	this->totalHp = 0;
	this->maxHp = 0;
	this->xp = 0;
	this->xpToUp = (100 * level);
	this->mana = 0;
	this->stamina = 0;
	this->arrows = 0;
	this->maxMana = 0;
	this->maxStamina = 0;
	this->maxArrows = 0;
	this->dmg = 0;
	this->defence = 0;
	cout << "contructor worked" << endl;
}

Character::~Character()
{
	cout << "destructor has worked..." << endl;
}

void Character::selectClass()
{
	char i;
	do {
		cout << "chose your class:\n1. Warrior\n2. Archer\n3. Mage" << endl;
		cin >> i;
		switch (i)
		{
		case '1':
		{
			this->Class = "warrior";
			this->hp = 200;
			this->totalHp = 200;
			this->maxHp = 200;
			this->stamina = 135;
			this->maxStamina = (125+(10*level));
			this->dmg = 10 + (5 * level);
			this->defence = 8+(3*level);
			break;
		}
		case '2':
		{
			this->Class = "archer";
			this->hp = 175;
			this->totalHp = hp;
			this->maxHp = totalHp;
			this->xp = 0;
			this->xpToUp = (100 * level);
			this->stamina = 110;
			this->maxStamina = (100 +(10 * level));
			this->arrows = 35;
			this->maxArrows = (30 + (5 *level));
			this->dmg = 15 + (7 * level);
			this->defence = 4 + (2 * level);
			break;
		}
		case '3':
		{
			this->Class = "mage";
			this->hp = 150;
			this->totalHp = hp;
			this->maxHp = totalHp;
			this->xp = 0;
			this->xpToUp = (100 * level);
			this->mana = 110;
			this->maxMana = (100 + (10 * level));
			this->stamina = 110;
			this->maxStamina = (100 + (10 * level));
			this->dmg = 20 + (10 * level);
			this->defence = 1 + (1 * level);
			break;
		}
		default:
			break;
		}
	} while (i != '1' && i != '2' && i != '3');
}
	//SETTERS
void Character::setName()
{
	string name;
	cout << "Enter your character name: " << endl;
	cin.ignore();
	getline(std::cin, name);

	this->name=name;
}

void Character::setLevel(int level)
{
	this-> level = level;
}

void Character::setMaxStamina(int maxStamina)
{
	this->maxStamina = maxStamina;
}

void Character::setMaxMana(int maxMana)
{
	this->maxMana = maxMana;
}

void Character::setMaxArrows(int maxArrows)
{
	this->maxArrows = maxArrows;
}
void Character::setArrows(int arrows)
{
	this->arrows = arrows;
}

void Character::setStamina(int stamina)
{
	this->stamina = stamina;
}

void Character::setMana(int mana)
{
	this->mana = mana;
}

void Character::setMaxHp(int maxHp)
{
	this->maxHp = maxHp;
}

void Character::setTotalHp(int totalHp)
{
	this->totalHp = totalHp;
}
void Character::setHp(int hp)
{
	this->hp = hp;
}

void Character::setXpToUp(int xpToUp)
{
	this->xpToUp = xpToUp;
}
void Character::setXp(int xp)
{
	this->xp = xp;
}
	//GETTERS
string Character::getName()
{
	return name;
}

string Character::getClass()
{
	return Class;
}

int Character::getLevel()
{
	return level;
}

int Character::getMaxArrows()
{
	return maxArrows;
}

int Character::getMaxStamina()
{
	return maxStamina;
}

int Character::getMaxMp()
{
	return maxMana;
}
int Character::getMp()
{
	return mana;
}

int Character::getArrows()
{
	return arrows;
}

int Character::getStamina()
{
	return stamina;
}

int Character::getMaxHp()
{
	return maxHp;
}
int Character::getTotalHp()
{
	return totalHp;
}
int Character::getHp()
{
	return hp;
}

int Character::getXpToUp()
{
	return xpToUp;
}
int Character::getXp()
{
	return xp;
}

void Character::rest()
{
	if (getHp() <= getMaxHp() - 10) 
	{
		cout << "You have restored 10hp" << endl;
		heal(10);
	}
	else
	{
		cout << "You have restored " << (getMaxHp() - getHp()) << "hp" << endl;
		heal(getMaxHp() - getHp());
	}
	restoreStamina(getMaxStamina()-getStamina());
	cout << "You have recovered " << getMaxStamina() - getStamina() <<  "stamina" << endl;
	if (getClass() == "archer")
	{
		if(getArrows() <=getMaxArrows()-(3 * getLevel())) 
		{
			cout << "You made " << 3 * getLevel() << " arrows" << endl;
			makeArrows(3 * getLevel());
		}
		else {
			cout << "You made " << getMaxArrows() - getArrows() << " arrows" << endl;
			makeArrows(getMaxArrows() - getArrows());
		}
	}
	else if (getClass() == "mage")
	{
		if (getMp() <= getMaxMp() - 20) {
			cout << "You have recovered 20mp" << endl;
			restoreMp(20);
		}
		else {
			cout << "You have recovered " << getMaxMp() - getMp() << "mp" << endl;
			restoreMp(getMaxMp() - getMp());
		}
	}
}