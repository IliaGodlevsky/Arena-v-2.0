#pragma once

#ifndef WEAPON_H_
#define WEAPON_H_

#include "Unit.h"

class WeaponMagic : public Magic
{
public:
	WeaponMagic(std::string name, int duration, 
		int propability = 20);
protected:
	virtual bool IsCasted()const final;
	int propability;
};

class Degenerate : public WeaponMagic
{
public:
	Degenerate(std::string name, int duration,
		int degeneratin, int propability = 20);
	void Effect(Unit* unit)const override;
	void Uneffect(Unit* unit)const override;
};

class Weapon
{
public:
	Weapon(int damage);
	virtual void Injure(Unit* unit)const = 0;
protected:
	Battles damage;
};

class Sword : public Weapon
{
public:
	Sword(int damage);
	void Injure(Unit* unit)const override;
private:
	Magic* open_wounds;
};

class Axe : public Weapon
{
public:
	Axe(int damage);
	void Injure(Unit* unit)const override;
};
#endif