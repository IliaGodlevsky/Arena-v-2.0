#pragma once

#ifndef WEAPON_H_
#define WEAPON_H_

#include "Unit.h"

class Weapon
{
public:
	Weapon(int damage);
	Weapon(const Weapon& weapon);
	Weapon& operator=(const Weapon& weapon);
	virtual ~Weapon();
	virtual void Injure(Unit* unit)const = 0;
protected:
	Battles damage;
};

class Sword : public Weapon
{
public:
	Sword(int damage);
	Sword(const Sword& sword);
	Sword& operator=(const Sword& sword);
	~Sword();
	void Injure(Unit* unit)const override;
private:
	spell_ptr<Magic> open_wounds;
};

class Axe : public Weapon
{
public:
	Axe(int damage);
	Axe(const Axe& axe);
	Axe& operator=(const Axe& axe);
	~Axe();
	void Injure(Unit* unit)const override;
private:
	spell_ptr<Magic> crush;
};
#endif