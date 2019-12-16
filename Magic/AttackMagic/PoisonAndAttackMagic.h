#pragma once

#ifndef POISON_AND_ATTACK_DAMAGE_H_
#define POISON_AND_ATTACK_DAMAGE_H_

#include "PoisonMagic.h"
#include "AttackMa.h"

class PoisonAndAttackMagic
	: public PoisonMagic, public AttackMagic
{
public:
	PoisonAndAttackMagic(std::string name,
		int manaCost, int duration,
		int damage, int regenReduce);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit)const override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
protected:
	bool hasEqualParametres(const MagicPtr& magic)const override;
	void showData()const override;
	void putOn(Unit& unit)const override;
};

#endif