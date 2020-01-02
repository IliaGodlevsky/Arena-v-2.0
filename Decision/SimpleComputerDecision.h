#ifndef SIMPLE_COMPUTER_DECISION_H_
#define SIMPLE_COMPUTER_DECISION_H_

#include "RandomComputerDecision.h"

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
private:
	UnitPtr findUnitWithOutChosenMagic(const Unit&, const MagicPtr&,
		const Gladiators&)const;
};

#endif
