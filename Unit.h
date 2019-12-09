#ifndef UNIT_H_
#define UNIT_H_

#include "Level.h"
#include "Vitals.h"
#include "Magic.h"
#include "Shield.h"
#include "Armor.h"
#include "Weapon.h"
#include "Decision.h"
#include "SpellBook.h"
#include "SpellsOnMe.h"
#include "State.h"
#include "StateHolder.h"
#include "ItemFactory.h"

#include "Globals.h"

class Unit
{
public:
	friend bool Weapon::canSmashUnit(const Unit& unit)const;
	friend class ComputerDecision;
public:
	Unit(std::string name, std::shared_ptr<Decision> decision);
	virtual ~Unit();
public:
	bool isEnoughManaFor(const MagicPtr& magic)const;
	bool takeDamage(int damage);
	bool injureUnit(Unit& unit);
	bool castMagic(Unit& unit, MagicPtr& magic);
	bool isAlive()const;
public:
	void takeMagic(const ItemFactory<Magic>& magicFactory);
	void takeWeapon(const ItemFactory<Weapon>& weaponFactory);
	void takeArmor(const ItemFactory<Armor>& armorFactory);
	void takeShield(const ItemFactory<Shield>& sheildFactory);
public:
	void payMana(int manaCost);
	void showFullInfo()const;
	void levelUp();
	void recieveNewState(std::shared_ptr<UnitState> unitState);
	void moveIntoNewRound();
public:
	const std::string& getName()const;
	UnitPtr chooseUnitToAttack(const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const MagicPtr& magicToCast_ptr, const Gladiators& units)const;
public:
	Battles m_damage = Battles(4);
	Battles m_armor = Battles(2);
	Vitals m_health = { 100,100,2 };
	Vitals m_mana = { 20,20,1 };
	SpellsOnMe m_magicOnMe;
	SpellBook m_magicBook;
	Level m_level;
	StateHolder m_stateHolder;
private:
	std::string m_name;
	std::shared_ptr<Decision> m_decision;
private:
	WeaponPtr m_weapon;
	ArmPtr m_mail;
	ShieldPtr m_shield;
private:
	int calculateDamageAbsorb(int damage)const;
};

#endif