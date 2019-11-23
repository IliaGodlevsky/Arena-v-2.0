#ifndef DECISION_H_
#define DECISION_H_

#include "Globals.h"

size_t RandInd(size_t max_index);

class Decision
{
public:
	Decision(const std::vector<UnitPtr>&);
	virtual UnitPtr ChooseUnitToAttack(const UnitPtr& deciding_unit)const = 0;
	virtual MagicPtr ChooseMagicToCast(const UnitPtr& deciding_unit)const = 0;
	virtual UnitPtr ChooseUnitToCast(const UnitPtr& deciding_unit, 
		const MagicPtr& magic_to_spell)const = 0;
protected:
	virtual bool SameUnit(const UnitPtr&, const UnitPtr&)const final;
	virtual bool CanCastBuff(UnitPtr caster, UnitPtr aim, 
		const MagicPtr& spell)const;
	virtual bool CanCastDebuff(UnitPtr caster, UnitPtr aim, 
		const MagicPtr& spell)const;
protected:
	const std::vector<UnitPtr>& arena;
};

class HumanDecision : public Decision
{
public:
	HumanDecision(const std::vector<UnitPtr>&);
	UnitPtr ChooseUnitToAttack(const UnitPtr& deciding_unit)const;
	MagicPtr ChooseMagicToCast(const UnitPtr& deciding_unit)const;
	UnitPtr ChooseUnitToCast(const UnitPtr& deciding_unit, 
		const MagicPtr& magic_to_spell)const;
private:
	void EatLine()const;
	bool Error(int choice, int upper, int lower)const;
	int Input(const std::string& message, int upper, int lower)const;
	void ShowUnits()const;
	bool WrongSpellToCast(const UnitPtr& caster, const UnitPtr& aim,
		const MagicPtr& spell)const;
private:
	const std::string UNIT_TO_ATTACK_CHOOSE = "Choose unit to attack: ";
	const std::string MAGIC_CHOOSE = "Choose magic: ";
	const std::string UNIT_TO_CAST_CHOOSE = "Choose unit to charm: ";
};

class ComputerDecision : public Decision
{
public:
	ComputerDecision(const std::vector<UnitPtr>&);
	UnitPtr ChooseUnitToAttack(const UnitPtr& deciding_unit)const;
	MagicPtr ChooseMagicToCast(const UnitPtr& deciding_unit)const;
	UnitPtr ChooseUnitToCast(const UnitPtr& deciding_unit, 
		const MagicPtr& magic_to_spell)const;
private:
	bool CanSmash(const UnitPtr& attacker, const UnitPtr& unit)const;
	UnitPtr FindUnitToSmash(const UnitPtr& attacker)const;
	UnitPtr ChooseRandomUnit(const UnitPtr& attacker)const;
	bool CanCastBuff(const UnitPtr& caster, const UnitPtr& aim, 
		const MagicPtr& spell)const;
	bool CanCastDebuff(const UnitPtr& caster, const UnitPtr& aim, 
		const MagicPtr& spell)const;
private:
	UnitPtr unit_to_cast;
	UnitPtr unit_to_attack;
	MagicPtr spell_to_cast;
};

#endif