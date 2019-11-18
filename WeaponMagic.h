#pragma once

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
	void Effect(UnitPtr unit) override;
	void Uneffect(UnitPtr unit)const override;
	MagicPtr Clone()const override;
protected:
	int degeneration;
};

class Crush : public WeaponMagic
{
public:
	Crush(std::string name, int damage,
		int propability = 20);
	void Effect(UnitPtr unit) override;
	void Uneffect(UnitPtr unit)const override;
	MagicPtr Clone()const override;
protected:
	int damage;
};