#ifndef DECISION_H_
#define DECISION_H_

#include "../Globals/Globals.h"

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
	virtual ~Decision() = default;
protected:
	virtual bool isSameUnit(const Unit&, const Unit&)const final;
	virtual bool canCastBuffOnUnit(const Unit& caster, const Unit& aim, 
		const MagicPtr& magic)const;
	virtual bool canCastDebuffOnUnit(const Unit& caster, const Unit& aim, 
		const MagicPtr& magic)const;
	virtual bool isWrongSpellToCast(const Unit& caster, const Unit& aim,
		const MagicPtr& spell)const;
protected:
	mutable bool m_wantToCastMagic = false;
};

#endif