#ifndef ARMOR_H_
#define ARMOR_H_

#include "Globals.h"
#include "Battles.h"
#include "Vitals.h"
#include "DefenceEquipment.h"

class Armor
{
public:
	explicit Armor(int armor);
	virtual void PutOn(UnitPtr unit)const = 0;
	virtual void PutOff(UnitPtr unit)const = 0;
protected:
	Battles armor;
};

class LetherArmor : public Armor
{
public:
	LetherArmor(int armor);
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