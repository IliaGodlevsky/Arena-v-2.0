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
		int reflect_chance);
	virtual void PutOn(Unit& unit)const;
	virtual void PutOff(Unit& unit)const;
	virtual void ShowFullInfo()const;
	virtual bool Reflect()const final;
	virtual ~Shield() = default;
protected:
	int reflect_chance;
};

class TowerShield : public Shield
{
public:
	TowerShield(std::string name, int armor, 
		Vitals health, int reflect_chance);
	void PutOn(Unit& unit)const;
	void PutOff(Unit& unit)const;
	void ShowFullInfo()const override;
protected:
	Vitals health;
};

class LegionShield : public Shield
{
public:
	LegionShield(std::string name,int armor, 
		Vitals health, Vitals mana, 
		int reflcet_chance);
	void PutOn(Unit& unit)const;
	void PutOff(Unit& unit)const;
	void ShowFullInfo()const override;
protected:
	Vitals health;
	Vitals mana;
};

#endif