#pragma once

#ifndef ATTACK_AND_STUN_MAGIC_H_
#define ATTACK_AND_STUN_MAGIC_H_

#include "AttackMa.h"
class AttackAndStunMagic : public AttackMagic
{
public:
	AttackAndStunMagic(std::string name, int manaCost,
		int duration, int damage);
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