#pragma once

#ifndef SHEILD_H_
#define SHIELD_H_

#include "Armor.h"
#include "Vitals.h"
#include "PosibilityCounter.h"

class Shield : public Armor
{
public:
	Shield(std::string name, int armor, 
		int reflectChance);
	virtual void showFullInfo()const override;
	virtual bool isReflectChance()const final;
	virtual ~Shield() = default;
protected:
	int m_reflectChance;
};

class TowerShield : public Shield
{
public:
	TowerShield(std::string name, int armor, 
		Vitals health, int reflect_chance);
	void putOn(Unit& unit)const override;
	void putOff(Unit& unit)const override;
	void showFullInfo()const override;
protected:
	Vitals m_health;
};

class LegionShield : public Shield
{
public:
	LegionShield(std::string name,int armor, 
		Vitals health, Vitals mana, 
		int reflcet_chance);
	void putOn(Unit& unit)const override;
	void putOff(Unit& unit)const override;
	void showFullInfo()const override;
protected:
	Vitals m_health;
	Vitals m_mana;
};

#endif