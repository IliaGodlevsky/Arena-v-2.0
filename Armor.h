#pragma once

#ifndef ARMOR_H_
#define ARMOR_H_

#include "Unit.h"

class Armor
{
public:
	Armor(int armor);
	virtual void PutOn(UnitPtr unit)const = 0;
	virtual void PutOff(UnitPtr unit)const = 0;
	virtual ~Armor() = default;
protected:
	Battles armor;
};

class Mail : public Armor
{
public:
	Mail(int armor, Vitals health);
	void PutOn(UnitPtr unit)const override;
	void PutOff(UnitPtr unit)const override;
private:
	Vitals health;
};

class WizardCloak : public Armor
{
public:
	WizardCloak(int armor, Vitals mana);
	void PutOn(UnitPtr unit)const override;
	void PutOff(UnitPtr unit)const override;
private:
	Vitals mana;
};


#endif