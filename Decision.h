#ifndef DECISION_H_
#define DECISION_H_

#include "Globals.h"
#include "State.h"

size_t RandInd(size_t max_index);

class Decision
{
public:
	Decision(const std::vector<Unit*>&);
	virtual Unit* ChooseUnitToAttack(const Unit&)const = 0;
	virtual MagicPtr ChooseMagicToCast(const Unit&)const = 0;
	virtual Unit* ChooseUnitToCast(const Unit&, const MagicPtr&)const = 0;
	virtual ~Decision() = default;
protected:
	virtual bool SameUnit(const Unit&, const Unit&)const final;
	virtual bool CanCastBuff(const Unit& caster, const Unit& aim, 
		const MagicPtr& spell)const;
	virtual bool CanCastDebuff(const Unit& caster, const Unit& aim, 
		const MagicPtr& spell)const;
protected:
	const std::vector<Unit*> arena;
};

class HumanDecision : public Decision
{
public:
	HumanDecision(const std::vector<Unit*>&);
	Unit* ChooseUnitToAttack(const Unit& deciding_unit)const;
	MagicPtr ChooseMagicToCast(const Unit& deciding_unit)const;
	Unit* ChooseUnitToCast(const Unit& deciding_unit, 
		const MagicPtr& magic_to_spell)const;
private:
	bool WrongSpellToCast(const Unit& caster, const Unit& aim,
		const MagicPtr& spell)const;
private:
	const std::string UNIT_TO_ATTACK_CHOOSE = "Choose unit to attack: ";
	const std::string MAGIC_CHOOSE = "Choose magic: ";
	const std::string UNIT_TO_CAST_CHOOSE = "Choose unit to charm: ";
};

//class ComputerDecision : public Decision
//{
//public:
//	ComputerDecision(const std::vector<Unit*>&);
//	Unit* ChooseUnitToAttack(const Unit& deciding_unit)const;
//	MagicPtr ChooseMagicToCast(const Unit& deciding_unit)const;
//	Unit* ChooseUnitToCast(const Unit& deciding_unit, 
//		const MagicPtr& magic_to_spell)const;
//private:
//	MagicPtr magic = nullptr;
//	Unit* unit_to_cast = nullptr;
//	Unit* unit_to_attack = nullptr;
//};

#endif