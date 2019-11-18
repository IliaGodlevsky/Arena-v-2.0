#pragma once

#ifndef DECISION_H_
#define DECISION_H_

#include <vector>

#include "Unit.h"

class Decision
{
public:
	Decision(const std::vector<Unit*>&);
	virtual Unit* ChooseUnitToAttack(Unit* deciding_unit) = 0;
	virtual Magic* ChooseMagicToCast(Unit* deciding_unit) = 0;
	virtual Unit* ChooseUnitToCast(Unit* deciding_unit) = 0;
protected:
	std::vector<Unit*>* arena;
};

class HumanDecision : public Decision
{
public:
	Unit* ChooseUnitToAttack(Unit* deciding_unit) override;
	Magic* ChooseMagicToCast() override;
	Unit* ChooseUnitToCast(Unit* deciding_unit) override;
};

class ComputerDecision : public Decision
{
public:
	Unit* ChooseUnitToAttack(Unit* deciding_unit) override;
	Magic* ChooseMagicToCast() override;
	Unit* ChooseUnitToCast(Unit* deciding_unit) override;
};

#endif