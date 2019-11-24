#ifndef ARMOR_H_
#define ARMOR_H_

#include "Globals.h"
#include "Battles.h"
#include "Vitals.h"

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
	explicit LetherArmor(int armor);
	void PutOn(UnitPtr unit)const;
	void PutOff(UnitPtr unit)const;

};

class Mail : public Armor
{
public:
	explicit Mail(int armor, Vitals health);
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