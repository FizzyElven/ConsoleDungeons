#pragma once
#include <iostream>
using namespace std;

class Weapon
{
private:

public:
	virtual void attack() = 0;
	virtual ~Weapon();
};

class Sword : public Weapon
{
public:
	void attack() override;
	~Sword() override {};
};