#pragma once

#ifndef WEAPON_H_
#define WEAPON_H_

#include "Unit.h"

class WeaponMagic : public Magic
{
public:
	WeaponMagic(std::string name, int duration, 
		int propability = 20);
	virtual ~WeaponMagic();
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
	Degenerate* Clone()const override;
protected:
	int degeneration;
};

class Crush : public WeaponMagic
{
public:
	Crush(std::string name, int damage, 
		int propability = 20);
	void Effect(Unit* unit)const override;
	void Uneffect(Unit* unit)const override;
	Crush* Clone()const override;
protected:
	int damage;
};

class Weapon
{
public:
	Weapon(int damage);
	virtual ~Weapon();
	virtual void Injure(Unit* unit)const = 0;
protected:
	Battles damage;
};

class Sword : public Weapon
{
public:
	Sword(int damage);
	~Sword();
	void Injure(Unit* unit)const override;
private:
	Magic* open_wounds;
};

class Axe : public Weapon
{
public:
	Axe(int damage);
	~Axe();
	void Injure(Unit* unit)const override;
private:
	Magic* crush;
};
#endif