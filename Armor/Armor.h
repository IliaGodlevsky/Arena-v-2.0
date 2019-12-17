#ifndef ARMOR_H_
#define ARMOR_H_

#include "../Globals/Globals.h"
#include "../Battles/Battles.h"
#include "../Vitals/Vitals.h"

class Armor;
using ArmPtr = std::unique_ptr<Armor>;

class Armor
{
public:
	Armor(std::string name, int armor);
	virtual void putOn(Unit& unit)const;
	virtual void putOff(Unit& unit)const;
	virtual ~Armor() = default;
	virtual void showFullInfo()const;
	virtual void showShortInfo()const final;
	virtual ArmPtr clone()const;
protected:
	std::string m_name;
	Battles m_armor;
};

class Mail : public Armor
{
public:
	Mail(std::string name, 
		int armor, Vitals health);
	void putOn(Unit& unit)const override;
	void putOff(Unit& unit)const override;
	void showFullInfo()const override;
	ArmPtr clone()const;
private:
	Vitals m_health;
};

class WizardCloak : public Armor
{
public:
	WizardCloak(std::string name, 
		int armor, Vitals mana);
	void putOn(Unit& unit)const override;
	void putOff(Unit& unit)const override;
	void showFullInfo()const override;
	ArmPtr clone()const;
private:
	Vitals m_mana;
};

class LegionerChains : public Armor
{
public:
	LegionerChains(std::string name, int armor, 
		Vitals health, Vitals mana);
	void putOn(Unit& unit)const override;
	void putOff(Unit& unit)const override;
	void showFullInfo()const override;
	ArmPtr clone()const;
private:
	Vitals m_health;
	Vitals m_mana;
};
#endif