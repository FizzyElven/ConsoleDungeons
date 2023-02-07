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
	void heal(int heal)
	{
		setHp(getHp() + heal);
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
			setXp(0);
			if(overXp>0){setXp(getXp() + overXp);}
			setXpToUp(100 * getLevel());
			if (getClass() == "warrior") 
			{
				setMaxHp(getMaxHp() + 10);
				setMaxStamina(getMaxStamina()+ 10);
				dmg += 5;
				defence += 3;
			}
			else if (getClass() == "archer")
			{
				setMaxHp(getMaxHp() + 10);
				setMaxStamina(getMaxStamina() + 10);
				dmg += 7;
				defence += 2;
				setMaxArrows(getMaxArrows() + 5);
			}
			else
			{
				setMaxHp(getMaxHp() + 10);
				setMaxStamina(getMaxStamina() + 10);
				dmg += 10;
				defence += 1;
				setMaxMana(getMaxMp() + 10);
			}
		}
	}
private:
	string name, Class;
	int level, xp, xpToUp, hp, totalHp, 
		maxHp, mana, stamina, arrows,
		maxMana, maxStamina, maxArrows;

};
