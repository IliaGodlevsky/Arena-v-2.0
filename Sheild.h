#pragma once

#ifndef SHEILD_H_
#define SHIELD_H_

#include "Armor.h"
#include "Vitals.h"

class Shield : public Armor
{
public:
	Shield(int armor, int reflect_chance);
	virtual void PutOn(UnitPtr unit)const;
	virtual void PutOff(UnitPtr unit)const;
	virtual bool Reflect()const;
protected:
	int reflect_chance;
	Battles armor;
};

class TowerShield : public Shield
{
public:
	TowerShield(int armor, Vitals health, 
		int reflect_chance);
	void PutOn(UnitPtr unit)const;
	void PutOff(UnitPtr unit)const;
	bool Reflect()const;
protected:
	Vitals health;
};

class LegionShield : public Shield
{
public:
	LegionShield(int armor, Vitals health,
		Vitals mana, int reflcet_chance);
	void PutOn(UnitPtr unit)const;
	void PutOff(UnitPtr unit)const;
	bool Reflect()const;
protected:
	Vitals health;
	Vitals mana;
};

#endif