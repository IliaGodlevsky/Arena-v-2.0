#pragma once

#ifndef UNIT_H_
#define UNIT_H_

#include <vector>
#include <string>

#include "Vitals.h"
#include "Decision.h"
#include "Armor.h"
#include "Weapon.h"

// abstract class Unit
class Unit
{
public:
	Unit();
	Unit(const Unit& unit);
	virtual void take_arm(Weapon* weapon) = 0;
	virtual void take_magic(Magic* magic) = 0;
	virtual Unit* act(Decision* decision) = 0;
	virtual bool injure(const Weapon* weapon, 
		Unit* unit) = 0;
	virtual bool spell(const Magic* magic,
		Unit* unit) = 0;
	void show()const;
protected:
	std::vector<Magic*> on_me;
	std::vector<Armor*> armors;
	std::vector<Weapon*> weapons;
	std::vector<Magic*> magic;
protected:
	std::string name;
	Vital health;
	Vital mana;
};

class Warrior : public Unit
{

};

class Wizard : public Unit
{

};

#endif