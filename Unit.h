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
	int CalcDamage()const;
	void TakeDamage(int damage);
	int CalcReduce(int damage);
public:
	Battles damage;
	Battles armor;
	Vitals health;
	Vitals mana;
	SpellBook spell_book;
	SpellsOnMe on_me;
private:
	Weapon* weapon;
	Armor* mail;
};

#endif