#pragma once

#ifndef DECISION_H_
#define DECISION_H_

#include <vector>

#include "Unit.h"

class Decision
{
public:
	Decision(Unit*, const std::vector<Unit*>&);
	virtual Unit* ChooseUnitToAttack() = 0;
	virtual Magic* ChooseMagicToCast() = 0;
	virtual Unit* ChooseUnitToCast() = 0;
protected:
	std::vector<Unit*>* arena;
	Unit* deciding_unit;
};

class HumanDecision : public Decision
{
public:
	Unit* ChooseUnitToAttack() override;
	Magic* ChooseMagicToCast() override;
	Unit* ChooseUnitToCast() override;
};

class ComputerDecision : public Decision
{
public:
	Unit* ChooseUnitToAttack() override;
	Magic* ChooseMagicToCast() override;
	Unit* ChooseUnitToCast() override;
};

#endif