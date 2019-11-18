#pragma once

#ifndef DECISION_H_
#define DECISION_H_

#include <vector>

#include "Unit.h"

class Decision
{
public:
	Decision(const std::vector<Unit*>&);
	virtual UnitPtr ChooseUnitToAttack(Unit* deciding_unit) = 0;
	virtual MagicPtr ChooseMagicToCast(Unit* deciding_unit) = 0;
	virtual UnitPtr ChooseUnitToCast(Unit* deciding_unit) = 0;
protected:
	std::vector<Unit*>* arena;
};

class HumanDecision : public Decision
{
public:
};

class ComputerDecision : public Decision
{
public:
};

#endif