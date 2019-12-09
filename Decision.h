#ifndef DECISION_H_
#define DECISION_H_

#include "Globals.h"
#include "State.h"

class Decision
{
public:
	Decision();
	virtual UnitPtr chooseUnitToAttack(const Unit&, const Gladiators&)const = 0;
	virtual MagicPtr chooseMagicToCast(const Unit&, const Gladiators&)const = 0;
	virtual UnitPtr chooseUnitToCast(const Unit&, const MagicPtr&, const Gladiators&)const = 0;
	virtual ~Decision() = default;
protected:
	virtual bool isSameUnit(const Unit&, const Unit&)const final;
	virtual bool canCastBuffOnUnit(const Unit& caster, const Unit& aim, 
		const MagicPtr& magic)const;
	virtual bool canCastDebuffOnUnit(const Unit& caster, const Unit& aim, 
		const MagicPtr& magic)const;
protected:
	mutable bool m_wantToCastMagic = false;
};

class HumanDecision : public Decision
{
public:
	HumanDecision();
	UnitPtr chooseUnitToAttack(const Unit& decidingUnit, const Gladiators& units)const;
	MagicPtr chooseMagicToCast(const Unit& decidingUnit, const Gladiators& units)const;
	UnitPtr chooseUnitToCast(const Unit& decidingUnit, 
		const MagicPtr& magicToCast, const Gladiators& units)const;
private:
	bool isWrongSpellToCast(const Unit& caster, const Unit& aim,
		const MagicPtr& spell)const;
	void showUnits(const Gladiators& units)const;
	bool wantToCastMagic()const;
private:
	const std::string UNIT_TO_ATTACK_CHOOSE_MESSAGE = "Choose unit to attack: ";
	const std::string MAGIC_TO_CAST_CHOOSE_MESSAGE = "Choose magic: ";
	const std::string UNIT_TO_CAST_CHOOSE_MESSAGE = "Choose unit to charm: ";
};

#endif