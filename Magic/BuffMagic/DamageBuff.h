#pragma once

#ifndef DAMAGE_BUFF_H_
#define DAMAGE_BUFF_H_

#include "Magic.h"

class DamageBuff : virtual public Magic
{
public:
	DamageBuff(std::string name, int manaCost,
		int duration, int damageAmplify);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual bool isBuff()const override;
	virtual void showFullInfo()const override;
	virtual ~DamageBuff() = default;
protected:
	int m_damageAmplify;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void putOn(Unit& unit)const override;
	virtual void showData()const override;
};

#endif