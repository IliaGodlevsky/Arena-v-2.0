#pragma once

#ifndef HUMAN_DECISION_H_
#define HUMAN_DECISION_H_

#include "Decision.h"

class HumanDecision : public Decision
{
public:
	HumanDecision();
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const;
private:
	bool isWrongSpellToCast(const Unit& caster, const Unit& aim,
		const MagicPtr& spell)const;
	void showUnits(const Gladiators& units)const;
	bool wantToCastMagic()const;
private:
	const std::string WANT_TO_CAST_QUESTION = "do you want to cast a magic <1 - yes/0 - no>: ";
	const std::string UNIT_TO_ATTACK_CHOOSE_MESSAGE = "Choose unit to attack: ";
	const std::string MAGIC_TO_CAST_CHOOSE_MESSAGE = "Choose magic: ";
	const std::string UNIT_TO_CAST_CHOOSE_MESSAGE = "Choose unit to charm: ";
};

#endif