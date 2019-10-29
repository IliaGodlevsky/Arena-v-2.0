#pragma once

#ifndef UNIT_H_
#define UNIT_H_

#include <vector>
#include <string>

#include "Vitals.h"
#include "Decision.h"
#include "Armor.h"
#include "Weapon.h"
#include "UnitState.h"

// abstract class Unit
class Unit
{
public:
	Unit(const std::string& name, 
		const Vital& health, 
		const Vital& mana, 
		UnitState* state);
	Unit(const Unit& unit);
	Unit(Unit&& unit);
	Unit& operator=(const Unit& unit);
	Unit& operator=(Unit&& unit);
	virtual ~Unit();
public:
	void TakeArm(Weapon* weapon);
	void TakeMagic(Magic* magic);
	void TakeMagicOnMe(Magic* magic);
	void TakeArmor(Armor* armor);
	virtual void Act(Decision* decision) = 0;
	virtual bool Injure(const Weapon* weapon, Unit* unit) = 0;
	virtual bool Spell(const Magic* magic,Unit* unit) = 0;
	void Show()const;
	void SetState(UnitState* state);
public:
	void ChangeArmor(int armor);
	void ChangeDamage(int damage);
	int Damage()const;
	int Arm()const;
protected:
	void CopyMagicOnMe(const Unit& unit);
	void CopyArmor(const Unit& unit);
	void CopyWeapon(const Unit& unit);
	void CopyMagic(const Unit& unit);
	void CopyUnitsStuff(const Unit& unit);
private:
	template<typename Pointer>
	void ReleaseMemory(std::vector<Pointer> container);
protected:
	std::vector<Magic*> on_me;
	std::vector<Armor*> armors;
	std::vector<Weapon*> weapons;
	std::vector<Magic*> magic;
protected:
	std::string name;
	UnitState* current_state;
	Vital health;
	Vital mana;
};

class Warrior : virtual public Unit
{

};

class Wizard : virtual public Unit
{

};

class BattleWizard : 
	public Warrior, public Wizard
{

};

template<typename Pointer>
void Unit::ReleaseMemory(std::vector<Pointer> container)
{
	for (auto i : container)
		delete i;
}

#endif