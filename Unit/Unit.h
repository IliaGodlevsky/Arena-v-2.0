#ifndef UNIT_H_
#define UNIT_H_

#include "../Weapon/Weapon.h"
#include "../Decision/Decision.h"
#include "../UnitState/UnitState.h"
#include "../Battles/Battles.h"
#include "../Vitals/Vitals.h"
#include "../MagicBook/MagicBook.h"
#include "../StateHolder/StateHolder.h"
#include "../Level/Level.h"
#include "../MagicOnMe/MagicOnMe.h"
#include "../Armor/Armor.h"
#include "../Shield/Shield.h"
#include "../Factories/ItemFactory/ItemFactory.h"

class Unit
{
public:
	//friend class ComputerDecision;
public:
	Unit(DecisionPtr decision, ItemFactoryPtr factory);
	Unit(const Unit& unit);
public:
	virtual bool injureUnit(Unit& unit);
	virtual bool castMagic(Unit& unit, MagicPtr& magic);
	virtual void setName(std::string name)final;
	virtual void payMana(int manaCost);
	virtual bool isEnoughManaFor(const MagicPtr& magic)const;
	virtual ~Unit() = 0;
public:
	void showFullInfo()const;
	void levelUp();
	void recieveNewState(StatePtr unitState);
	void moveIntoNewRound();
	const std::string& getName()const;
	bool takeDamage(int damage);
	bool isAlive()const;
public:
	UnitPtr chooseUnitToAttack(const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const MagicPtr& magicToCast_ptr, 
		const Gladiators& units)const;
	//virtual UnitPtr clone()const;
public:
	Battles m_damage;
	Battles m_armor;
	Vitals m_health;
	Vitals m_mana;
	MagicOnMe m_magicOnMe;
	MagicBook m_magicBook;
	StateHolder m_stateHolder;
protected:
	std::unique_ptr<Level> m_level = nullptr;
protected:
	WeaponPtr m_weapon;
	ArmPtr m_mail;
	ShieldPtr m_shield;
private:
	std::string m_name;
	DecisionPtr m_decision;
private:
	int calculateDamageAbsorb(int damage)const;
};

#endif