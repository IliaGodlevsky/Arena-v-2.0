#ifndef HUMAN_DECISION_H_
#define HUMAN_DECISION_H_

#include "Decision.h"
#include "../MagicBook/MagicBook.h"

index chooseMagicIndex(const std::string& message, 
	const MagicBook& magicBook);

class HumanDecision : public Decision
{
public:
	HumanDecision();
	HumanDecision(const HumanDecision&) = default;
	HumanDecision(HumanDecision&& decision) = default;
	HumanDecision& operator=(const HumanDecision&) = default;
	HumanDecision& operator=(HumanDecision&&) = default;
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit, 
		const Gladiators& units)const override;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit, 
		const Gladiators& units)const override;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit,
		const MagicPtr& magicToCast, const Gladiators& units)const override;
	virtual std::string setName(std::string name)const override;
	std::string getDecisionType()const override;
	void takeMagic(Unit& decidingUnit, const Unit& victim) override;
	DecisionPtr clone()const;
private:
	bool wantToCastMagic(const Unit& decidingUnit)const;
	mutable bool m_wantToCastMagic = false;
	const char* wantToCastMsg = "do you want to cast a magic <1 - yes/0 - no>: ";
	const char* unitToAttackChooseMsg = "choose unit to attack: ";
	const char* magicToCastChooseMsg = "Choose magic: ";
	const char* unitToCastChooseMsg = "choose unit to charm: ";
	const char* magicToTakeMsg = "choose units spell you want to take: ";
	const char* haveMagicMsg = "You have such a magic. "
		"Do you really want to take it?: ";
};

#endif