#ifndef DECISION_H_
#define DECISION_H_

#include "../Globals/Globals.h"

bool isWrongUnitToAttack(const Unit& decidingUnit, const UnitPtr& unit);
bool canCastBuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic);
bool canCastDebuffOnUnit(const Unit& caster, const Unit& aim,
	const MagicPtr& magic);
bool isWrongSpellToCast(const Unit& caster, const Unit& aim,
	const MagicPtr& spell);

class Decision
{
public:
	Decision();
	Decision(const Decision&) = default;
	Decision(Decision&& decision) = default;
	Decision& operator=(const Decision&) = default;
	Decision& operator=(Decision&&) = default;
	virtual UnitPtr chooseUnitToAttack(const Unit&, const Gladiators&)const = 0;
	virtual MagicPtr chooseMagicToCast(const Unit&, const Gladiators&)const = 0;
	virtual UnitPtr chooseUnitToCast(const Unit&, const MagicPtr&, const Gladiators&)const = 0;
	virtual std::string setName(std::string name)const = 0;
	virtual std::string getDecisionType()const = 0;
	virtual void takeMagic(Unit& decidingUnit, const Unit& victim) = 0;
	virtual DecisionPtr clone()const = 0;
	virtual ~Decision() = default;
protected:

};

#endif