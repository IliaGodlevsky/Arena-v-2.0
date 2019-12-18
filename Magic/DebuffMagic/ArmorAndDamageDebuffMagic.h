#ifndef ARMOR_AND_DAMAGE_DEBUFF_H_
#define ARMOR_AND_DAMAGE_DEBUFF_H_

#include "ArmorDebuffMagic.h"
#include "DamageDebuffMagic.h"

class ArmorAndDamageDebuffMagic
	: public DamageDebuffMagic, public ArmorDebuffMagic
{
public:
	ArmorAndDamageDebuffMagic(std::string name, int manaCost,
		int duration, int armorReduce, int damageReduce);
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