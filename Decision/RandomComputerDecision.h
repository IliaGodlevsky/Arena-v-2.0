#ifndef COMPUTER_DECISION_H_
#define COMPUTER_DECISION_H_

#include "Decision.h"

class RandomComputerDecision : public Decision
{
public:
	RandomComputerDecision();
	RandomComputerDecision(const RandomComputerDecision&) = default;
	RandomComputerDecision(RandomComputerDecision&& decision) = default;
	RandomComputerDecision& operator=(const RandomComputerDecision&) = default;
	RandomComputerDecision& operator=(RandomComputerDecision&&) = default;
public:
	virtual UnitPtr chooseUnitToAttack(const Unit&, 
		const Gladiators&)const override;
	virtual MagicPtr chooseMagicToCast(const Unit&, 
		const Gladiators&)const override;
	virtual UnitPtr chooseUnitToCast(const Unit&, const MagicPtr&, 
		const Gladiators&)const override;
	virtual std::string setName(std::string name)const final;
	virtual std::string getDecisionType()const override final;
	virtual ~RandomComputerDecision() = default;
	virtual void takeMagic(Unit& decidingUnit, const Unit& victim) override final;
};

#endif