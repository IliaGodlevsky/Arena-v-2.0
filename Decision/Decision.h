#ifndef DECISION_H_
#define DECISION_H_

#include "../Globals/Globals.h"

class Decision;
using DecisionPtr = std::shared_ptr<Decision>;

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

#endif