#ifndef ARMOR_AND_DAMAGE_BUFF_H_
#define ARMOR_AND_DAMAGE_BUFF_H_

#include "../UnitParametresChangeMagic.h"
#include "../Elements/ArmorAmplifyElem.h"
#include "../Elements/DamageAmplifyElem.h"

class ArmorAndDamageBuffMagic
	: public UnitParametresChangeMagic
{
public:
	using UnitParametresChangeMagic::UnitParametresChangeMagic;
	ArmorAndDamageBuffMagic(std::string name, int manaCost,
		Time time, int armorAmplify, int damageAmplify);
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	~ArmorAndDamageBuffMagic() = default;
};

#endif