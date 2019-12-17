#pragma once

#ifndef OFFSET_DAMAGE_BUFF_H_
#define OFFSET_DAMAGE_BUFF_H_

#include "DamageBuffMagic.h"
#include "../DebuffMagic/ArmorDebuffMagic.h"

class OffsetDamageBuffMagic
	: public DamageBuffMagic, public ArmorDebuffMagic
{
public:
	OffsetDamageBuffMagic(std::string name, int manaCost,
		int duration, int armorReduce, int damageAmplify);
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