#ifndef ARMOR_AND_DAMAGE_BUFF_H_
#define ARMOR_AND_DAMAGE_BUFF_H_

#include "ArmorBuffMagic.h"
#include "DamageBuffMagic.h"

class ArmorAndDamageBuffMagic
	: public ArmorBuffMagic, public DamageBuffMagic
{
public:
	ArmorAndDamageBuffMagic(std::string name, int manaCost,
		int duration, int armorAmplify, int damageAmplify);
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