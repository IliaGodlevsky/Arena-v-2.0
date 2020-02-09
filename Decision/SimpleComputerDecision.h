#ifndef SIMPLE_COMPUTER_DECISION_H_
#define SIMPLE_COMPUTER_DECISION_H_

#include "RandomComputerDecision.h"

using Predicate = bool(*)(UnitPtr, UnitPtr);
using CastPredicate = bool(*)(UnitPtr, UnitPtr, MagicPtr&);
using MagicAim = std::pair<UnitPtr, MagicPtr>;
using DecisionPredicate = bool(*)(const Unit&, const Unit&, const MagicPtr&);

bool canKill(UnitPtr activeUnit, UnitPtr passiveUnit);
bool canBeKilled(UnitPtr activeUnit, UnitPtr passiveUnit);

bool isDeadAfterBuffAndHit(UnitPtr activeUnit, 
	UnitPtr passiveUnit, MagicPtr& buff);
bool isDeadAfterDebuffAndHit(UnitPtr activeUnit,
	UnitPtr passiveUnit, MagicPtr& debuff);

bool isDeadAfterDebuff(UnitPtr activeUnit,
	UnitPtr passiveUnit, MagicPtr& debuff);

class SimpleComputerDecision : public RandomComputerDecision
{
public:
	SimpleComputerDecision();
	SimpleComputerDecision(const SimpleComputerDecision&);
	SimpleComputerDecision(SimpleComputerDecision&&) = default;
	SimpleComputerDecision& operator=(const SimpleComputerDecision&) = default;
	SimpleComputerDecision& operator=(SimpleComputerDecision&&) = default;
	UnitPtr chooseUnitToAttack(const Unit&, const Gladiators&)const override;
	MagicPtr chooseMagicToCast(const Unit&, const Gladiators&)const override;
	UnitPtr chooseUnitToCast(const Unit&, const MagicPtr&, const Gladiators&)const override;
	virtual std::string getDecisionType()const override;
	DecisionPtr clone()const;
private:
	UnitPtr findUnitWithOutChosenMagic(const Unit&, const MagicPtr&,const Gladiators&)const;
	UnitPtr findUnitCanBeKilled(const Unit&, const Gladiators&, Predicate)const;
	MagicAim findMagicToKillUnit(const Unit&, const Gladiators&)const;
	MagicAim findUnitToKillWithWeaponAndMagic(const Unit&, const Gladiators&)const;
	MagicAim findMagicToPreventKill(const UnitPtr&enemy, const UnitPtr& deciding)const;
	bool isDeadAfterCast(const Unit& unit1, const UnitPtr& unit2, 
		MagicPtr& magic,CastPredicate castPredicate, DecisionPredicate predicate)const;
	UnitPtr getUnitPointer(const Unit& decidingUnit, const Gladiators& units)const;
	MagicAim makePair(std::vector<MagicAim>& pair)const;
	enum { UNIT_TO_CAST, MAGIC_TO_CAST };
	mutable UnitPtr m_unitToAttack = nullptr;
	mutable UnitPtr m_unitToCast = nullptr;
	mutable MagicPtr m_magicToCast = nullptr;
};

#endif
