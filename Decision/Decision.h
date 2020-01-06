#ifndef DECISION_H_
#define DECISION_H_

#include "../Globals/Globals.h"
#include "Alliance.h"

class Decision
{
public:
	Decision();
	Decision(const Decision&) = default;
	Decision(Decision&& decision) = default;
	Decision& operator=(const Decision&) = default;
	Decision& operator=(Decision&&) = default;
public:
	virtual UnitPtr chooseUnitToAttack(const Unit&, const Gladiators&)const = 0;
	virtual MagicPtr chooseMagicToCast(const Unit&, const Gladiators&)const = 0;
	virtual UnitPtr chooseUnitToCast(const Unit&, const MagicPtr&, const Gladiators&)const = 0;
	virtual std::string setName(std::string name)const = 0;
	virtual std::string getDecisionType()const = 0;
	virtual void takeMagic(Unit& decidingUnit, const Unit& victim) = 0;
	virtual void takeAlly(const UnitPtr& ally) final;
	virtual bool isAlly(const UnitPtr& unit)const final;
	virtual DecisionPtr clone()const = 0;
	virtual ~Decision() = default;
	virtual bool isSameUnit(const Unit&, const Unit&)const;
protected:
	virtual bool canCastBuffOnUnit(const Unit& caster, const Unit& aim, 
		const MagicPtr& magic)const;
	virtual bool canCastDebuffOnUnit(const Unit& caster, const Unit& aim, 
		const MagicPtr& magic)const;
	virtual bool isWrongSpellToCast(const Unit& caster, const Unit& aim,
		const MagicPtr& spell)const;
protected:
	Alliance m_allies;
};

#endif