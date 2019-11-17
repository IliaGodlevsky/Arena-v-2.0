#pragma once

#ifndef UNIT_H_
#define UNIT_H_

#include "Vitals.h"
#include "Magic.h"
#include "Armor.h"
#include "Weapon.h"
#include "Battles.h"

class Decision;

class Unit
{
public:
	bool Injure(Unit* unit, Weapon* weapon);
	bool Spell(Unit* unit, Magic* magic);
	void Act(Decision* decision);
	Battles damage;
	Battles armor;
	Vitals health;
	Vitals mana;
private:
	Weapon* weapon;
	Armor* armor;
};

#endif