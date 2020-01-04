#ifndef SIMPLE_COMPUTER_DECISION_H_
#define SIMPLE_COMPUTER_DECISION_H_

#include "RandomComputerDecision.h"

using Predicate = bool(*)(UnitPtr, UnitPtr);
using CastPredicate = bool(*)(UnitPtr, UnitPtr, MagicPtr&);

bool canKill(UnitPtr unit1, UnitPtr unit2);
bool canBeKilled(UnitPtr unit1, UnitPtr unit2);

bool isDeadAfterBuff(UnitPtr unit1, 
	UnitPtr unit2, MagicPtr& magic);
bool isDeadAfterDebuff(UnitPtr unit1,
	UnitPtr unit2, MagicPtr& magic);

class SimpleComputerDecision : public RandomComputerDecision
{
public:
	SimpleComputerDecision();
	SimpleComputerDecision(const SimpleComputerDecision&) = default;
	SimpleComputerDecision(SimpleComputerDecision&& decision) = default;
	SimpleComputerDecision& operator=(const SimpleComputerDecision&) = default;
	SimpleComputerDecision& operator=(SimpleComputerDecision&&) = default;
public:
	UnitPtr chooseUnitToAttack(const Unit&,
		const Gladiators&)const override;
	MagicPtr chooseMagicToCast(const Unit&,
		const Gladiators&)const override;
	UnitPtr chooseUnitToCast(const Unit&, const MagicPtr&,
		const Gladiators&)const override;
	virtual std::string getDecisionType()const override;
	DecisionPtr clone()const;
private:
	using DecisionPredicate = bool(SimpleComputerDecision::*)(const Unit&, const Unit&,
		const MagicPtr&)const;
	UnitPtr findUnitWithOutChosenMagic(const Unit&, const MagicPtr&,
		const Gladiators&)const;
	UnitPtr findUnitCanBeKilled(const Unit&, const Gladiators&, Predicate)const;
	std::pair<UnitPtr, MagicPtr> findMagicToKillUnit(const Unit&, const Gladiators&)const;
	std::pair<UnitPtr, MagicPtr> fingUnitToKillWithWeaponAndMagic(const Unit&, const Gladiators&)const;
	std::pair<UnitPtr, MagicPtr> findMagicToPreventKill(const UnitPtr&enemy, const UnitPtr& deciding)const;
	bool isDeadAfterCast(const Unit& unit1, const UnitPtr& unit2, 
		MagicPtr& magic,CastPredicate castPredicate, DecisionPredicate predicate)const;
	std::pair<UnitPtr, MagicPtr> makePair(std::vector<std::pair<UnitPtr, MagicPtr>>& pair)const;
private:
	enum { UNIT_TO_CAST, MAGIC_TO_CAST };
	mutable UnitPtr m_unitToAttack;
	mutable UnitPtr m_unitToCast;
	mutable MagicPtr m_magicToCast;
private:
	UnitPtr getUnitPointer(const Unit& decidingUnit, const Gladiators& units)const;
};

#endif
