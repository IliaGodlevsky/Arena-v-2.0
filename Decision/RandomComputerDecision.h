#ifndef COMPUTER_DECISION_H_
#define COMPUTER_DECISION_H_

#include "Decision.h"

class RandomComputerDecision : public Decision
{
public:
	RandomComputerDecision();
	UnitPtr chooseUnitToAttack(const Unit&, 
		const Gladiators&)const override;
	MagicPtr chooseMagicToCast(const Unit&, 
		const Gladiators&)const override;
	UnitPtr chooseUnitToCast(const Unit&, const MagicPtr&, 
		const Gladiators&)const override;
};

#endif