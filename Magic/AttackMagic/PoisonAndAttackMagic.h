#ifndef POISON_AND_ATTACK_DAMAGE_H_
#define POISON_AND_ATTACK_DAMAGE_H_

#include "PoisonMagic.h"
#include "../Elements/HpReduceElem.h"

class PoisonAndAttackMagic
	: public PoisonMagic
{
public:
	PoisonAndAttackMagic(std::string name,
		int manaCost, Time time,
		HpReduceElem damage, int regenReduce);
	PoisonAndAttackMagic(std::string name, int manaCost, Time time, 
		HpReduceElem damage, const ElementHolder& elements);
	void effectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
private:
	HpReduceElem m_damage;
};

#endif