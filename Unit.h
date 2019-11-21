#ifndef UNIT_H_
#define UNIT_H_

#include "Vitals.h"
#include "Magic.h"
#include "Sheild.h"
#include "Armor.h"
#include "Sheild.h"
#include "Weapon.h"
#include "Decision.h"

#include "Globals.h"

class Unit
{
public:
	void Act(Decision* decision);
	void TakeDamage(int damage);
	void ShowUnitName();
	void LevelUp();
public:
	Battles damage;
	Battles armor;
	Vitals health;
	Vitals mana;
	SpellsOnMe on_me;
	SpellBook spell_book;
private:
	std::unique_ptr<Weapon> weapon;
	std::unique_ptr<Armor> mail;
	std::unique_ptr<Shield> sheild;
private:
	int AbsorbCalc(int damage)const;
	bool Injure(UnitPtr unit);
	bool Spell(UnitPtr unit, MagicPtr& magic);
};

class Boss : public Unit
{

};

#endif