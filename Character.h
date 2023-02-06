#pragma once
#include "Weapon.h"
#include <windows.h>
#include <string>

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

	int heal(int heal)
	{
		setHp(getHp() + heal);
		return getHp();
	}

	Character();

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
	
private:
	string name, Class;
	int level, xp, xpToUp, hp, totalHp, 
		maxHp, mana, stamina, arrows,
		maxMana, maxStamina, maxArrows;

};
