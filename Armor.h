#ifndef ARMOR_H_
#define ARMOR_H_

#include "Globals.h"
#include "Battles.h"
#include "Vitals.h"

class Armor
{
public:
	Armor(std::string name, int armor);
	virtual void PutOn(Unit& unit)const;
	virtual void PutOff(Unit& unit)const;
	virtual ~Armor() = default;
	virtual void ShowFullInfo()const;
	virtual void ShowShortInfo()const final;
protected:
	std::string name;
	Battles armor;
};

class Mail : public Armor
{
public:
	Mail(std::string name, 
		int armor, Vitals health);
	void PutOn(Unit& unit)const override;
	void PutOff(Unit& unit)const override;
	void ShowFullInfo()const override;
private:
	Vitals health;
};

class WizardCloak : public Armor
{
public:
	WizardCloak(std::string name, 
		int armor, Vitals mana);
	void PutOn(Unit& unit)const override;
	void PutOff(Unit& unit)const override;
	void ShowFullInfo()const override;
private:
	Vitals mana;
};

class LegionerChains : public Armor
{
public:
	LegionerChains(std::string name, int armor, 
		Vitals health, Vitals mana);
	void PutOn(Unit& unit)const override;
	void PutOff(Unit& unit)const override;
	void ShowFullInfo()const override;
private:
	Vitals health;
	Vitals mana;
};
#endif