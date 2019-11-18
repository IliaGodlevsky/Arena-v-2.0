#pragma once

#ifndef UNIT_H_
#define UNIT_H_

#include "Vitals.h"
#include "Magic.h"
#include "Armor.h"
#include "Weapon.h"
#include "Battles.h"
#include "Decision.h"

class Unit;

using UnitPtr = std::shared_ptr<Unit>;

class Unit
{
public:
	bool Injure(UnitPtr unit);
	bool Spell(UnitPtr unit, MagicPtr& magic);
	void Act(Decision* decision);
	void TakeDamage(int damage);
public:
	Battles damage;
	Battles armor;
	Vitals health;
	Vitals mana;
	SpellsOnMe on_me;
private:
	int AbsorbCalc(int damage)const;
private:
	Spells spell_book;
	std::unique_ptr<Weapon> weapon;
	std::unique_ptr<Armor> mail;
};

class Boss : public Unit
{

};

#endif