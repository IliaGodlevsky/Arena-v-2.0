#ifndef DECISION_H_
#define DECISION_H_

#include "Globals.h"
#include "State.h"

class Decision
{
public:
	Decision(const std::vector<UnitPtr>&);
	virtual UnitPtr chooseUnitToAttack(const Unit&)const = 0;
	virtual MagicPtr chooseMagicToCast(const Unit&)const = 0;
	virtual UnitPtr chooseUnitToCast(const Unit&, const MagicPtr&)const = 0;
	virtual ~Decision() = default;
protected:
	virtual bool isSameUnit(const Unit&, const Unit&)const final;
	virtual bool canCastBuffOnUnit(const Unit& caster, const Unit& aim, 
		const MagicPtr& magic)const;
	virtual bool canCastDebuffOnUnit(const Unit& caster, const Unit& aim, 
		const MagicPtr& magic)const;
protected:
	mutable bool m_wantToCastMagic = false;
protected:
	const std::vector<UnitPtr> m_units;
};

class HumanDecision : public Decision
{
public:
	HumanDecision(const std::vector<UnitPtr>&);
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit)const;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit)const;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit, 
		const MagicPtr& magicToCast)const;
private:
	bool isWrongSpellToCast(const Unit& caster, const Unit& aim,
		const MagicPtr& spell)const;
	void showUnits()const;
	bool wantToCastMagic()const;
private:
	const std::string UNIT_TO_ATTACK_CHOOSE_MESSAGE = "Choose unit to attack: ";
	const std::string MAGIC_TO_CAST_CHOOSE_MESSAGE = "Choose magic: ";
	const std::string UNIT_TO_CAST_CHOOSE_MESSAGE = "Choose unit to charm: ";
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