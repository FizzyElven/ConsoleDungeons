#pragma once
#include <iostream>
#include <windows.h>
#include <string>
using namespace std;

class Character
{
public:
	//Setters
	void setName();
	void selectClass();
	void setLevel(int level), 
		setXp(int xp), setXpToUp(int xpToUp),
		setHp(int hp), setTotalHp(int totalHp), 
		setMaxHp(int maxHp),setMana(int mana),
		setStamina(int stamina), setArrows(int arrows),
	setMaxMana(int maxMana), setMaxStamina(int maxStamina),
		setMaxArrows(int maxArrows);
	//Getters
	string getName(), getClass();
	int getLevel(), getXp(), getXpToUp(),
		getHp(),getTotalHp(), getMaxHp(),
		getMp(), getStamina(), getArrows(),
		getMaxMp(), getMaxStamina(), getMaxArrows();
	int overXp;
	int heal(int heal)
	{
		setHp(getHp() + heal);
		return getHp();
	}

	Character();
	int dmg;
	int defence;
	//virtual void HUD();
	void rest();
	void restoreStamina(int restStamina)
	{
		setStamina(getStamina() + restStamina);
	}
	void restoreMp(int restMana)
	{
		setMana(getMp() + restMana);
	}
	void makeArrows(int makeArrow)
	{
		setArrows(getArrows() + makeArrow);
	}
	virtual ~Character();
	void lvlup() 
	{ 
		if (getXp() >= getXpToUp())
		{
			overXp = getXp() - getXpToUp();
			setLevel(getLevel() + 1);
			setXp(getXp() - getXpToUp());
			setXp(getXp() + overXp);
			setXpToUp(100 * getLevel());
			if (getClass() == "warrior") 
			{
				setMaxHp(getMaxHp() + (10 * level));
				setMaxStamina(getMaxStamina()+ (10 * level));
				dmg += (5 * level);
				defence += + (3 * level);
			}
			else if (getClass() == "archer")
			{
				setMaxHp(getMaxHp() + (10 * level));
				setMaxStamina(getMaxStamina() + (10 * level));
				dmg += (7 * level);
				defence += +(2 * level);
				setMaxArrows(getMaxArrows() + (5 * level));
			}
			else
			{
				setMaxHp(getMaxHp() + (10 * level));
				setMaxStamina(getMaxStamina() + (10 * level));
				dmg += (10 * level);
				defence += +(1 * level);
				setMaxMana(getMaxMp() + (10 * level));
			}
		}
	}
private:
	string name, Class;
	int level, xp, xpToUp, hp, totalHp, 
		maxHp, mana, stamina, arrows,
		maxMana, maxStamina, maxArrows;

};
