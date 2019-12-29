#ifndef HUMAN_DECISION_H_
#define HUMAN_DECISION_H_

#include "Decision.h"

class HumanDecision : public Decision
{
public:
	HumanDecision();
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit, 
		const Gladiators& units)const override;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit, 
		const Gladiators& units)const override;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const override;
	virtual std::string setName(std::string name)const override;
	std::string getDecisionType()const override;
private:
	bool wantToCastMagic(const Unit& decidingUnit)const;
private:
	const std::string WANT_TO_CAST_QUESTION = "do you want to cast a magic <1 - yes/0 - no>: ";
	const std::string UNIT_TO_ATTACK_CHOOSE_MESSAGE = "Choose unit to attack: ";
	const std::string MAGIC_TO_CAST_CHOOSE_MESSAGE = "Choose magic: ";
	const std::string UNIT_TO_CAST_CHOOSE_MESSAGE = "choose unit to charm: ";
};

#endif