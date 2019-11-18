#pragma once

#include "Unit.h"

#ifndef WEAPON_MAGIC_H_
#define WEAPON_MAGIC_H_

class WeaponMagic : public Magic
{
public:
	WeaponMagic(std::string name, int duration,
		int propability = 20);
	virtual ~WeaponMagic();
public:
	friend bool operator==(const WeaponMagic& first, const WeaponMagic& second);
	friend bool operator!=(const WeaponMagic& first, const WeaponMagic& second);
protected:
	virtual bool IsCasted()const final;
	int propability;
};

class Degenerate : public WeaponMagic
{
public:
	Degenerate(std::string name, int duration,
		int degeneratin, int propability = 20);
	void Effect(UnitPtr unit);
	void Uneffect(UnitPtr unit)const;
	MagicPtr Clone()const override;
public:
	friend bool operator==(const Degenerate& first, const Degenerate& second);
	friend bool operator!=(const Degenerate& first, const Degenerate& second);
protected:
	int degeneration;
};

class Crush : public WeaponMagic
{
public:
	Crush(std::string name, int damage,
		int propability = 20);
	void Effect(UnitPtr unit);
	void Uneffect(UnitPtr unit)const;
	MagicPtr Clone()const override;
public:
	friend bool operator==(const Crush& first, const Crush& second);
	friend bool operator!=(const Crush& first, const Crush& second);
protected:
	int damage;
};

#endif