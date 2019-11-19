#ifndef DECISION_H_
#define DECISION_H_

#include "Globals.h"

class Decision
{
public:
	Decision(std::vector<UnitPtr>&);
	virtual UnitPtr ChooseUnitToAttack(UnitPtr deciding_unit) = 0;
	virtual MagicPtr ChooseMagicToCast(UnitPtr deciding_unit) = 0;
	virtual UnitPtr ChooseUnitToCast(UnitPtr deciding_unit, const MagicPtr& magic_to_spell) = 0;
protected:
	std::vector<UnitPtr> arena;
};

class HumanDecision : public Decision
{
public:
	HumanDecision(std::vector<UnitPtr>&);
	UnitPtr ChooseUnitToAttack(UnitPtr deciding_unit);
	MagicPtr ChooseMagicToCast(UnitPtr deciding_unit);
	UnitPtr ChooseUnitToCast(UnitPtr deciding_unit, const MagicPtr& magic_to_spell);
private:
	void EatLine()const;
	bool Error(int choice, int upper, int lower)const;
	int Input(const std::string& message, int upper, int lower)const;
	void ShowUnits()const;
private:
	const std::string UNIT_TO_ATTACK_CHOOSE = "Choose unit to attack: ";
	const std::string MAGIC_CHOOSE = "Choose magic: ";
	const std::string UNIT_TO_CAST_CHOOSE = "Choose unit to charm: ";
};

class ComputerDecision : public Decision
{
public:
	ComputerDecision(std::vector<UnitPtr>&);
	UnitPtr ChooseUnitToAttack(UnitPtr deciding_unit);
	MagicPtr ChooseMagicToCast(UnitPtr deciding_unit);
	UnitPtr ChooseUnitToCast(UnitPtr deciding_unit, const MagicPtr& magic_to_spell);
};

#endif