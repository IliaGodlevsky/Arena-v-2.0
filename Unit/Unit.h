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
	virtual ~Unit() = default;
public:
	void takeKilledUnitMagic(const Unit& victim);
	void showFullInfo()const;
	void levelUp();
	void recieveNewState(StatePtr unitState);
	void moveIntoNewRound();
	const std::string& getName()const;
	bool isAlive()const;
	bool takeDamage(int damage);
	void takeAlly(const UnitPtr& unit);
	bool isAlly(const UnitPtr& unit)const;
public:
	UnitPtr chooseUnitToAttack(const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const MagicPtr& magicToCast_ptr, 
		const Gladiators& units)const;
	virtual UnitPtr getPureClone()const;
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
	WeaponPtr m_weapon = nullptr;
	ArmPtr m_mail = nullptr;
	ShieldPtr m_shield = nullptr;
private:
	std::string m_name;
	DecisionPtr m_decision = nullptr;
protected:
	int calculateDamageAbsorb(int damage)const;
};

#endif