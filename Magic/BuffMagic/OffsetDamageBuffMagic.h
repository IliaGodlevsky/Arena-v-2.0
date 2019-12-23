#ifndef OFFSET_DAMAGE_BUFF_H_
#define OFFSET_DAMAGE_BUFF_H_

#include "../DebuffMagic/ArmorDebuffMagic.h"

#include "DamageBuffMagic.h"

class OffsetDamageBuffMagic
	: public DamageBuffMagic, public ArmorDebuffMagic
{
public:
	OffsetDamageBuffMagic(std::string name, int manaCost,
		const Timer& timer, int armorReduce, int damageAmplify);
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