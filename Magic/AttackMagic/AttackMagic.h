#pragma once

#ifndef ATTACK_MAGIC_H_
#define ATTACK_MAGIC_H_

#include "../Magic.h"
#include "../../Globals/Globals.h"

class AttackMagic : virtual public Magic
{
public:
	AttackMagic(std::string name, int manaCost, int damage);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual ~AttackMagic() = default;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
protected:
	int m_damage;
};

#endif