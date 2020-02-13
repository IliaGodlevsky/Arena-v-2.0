#ifndef ARMOR_AND_DAMAGE_DEBUFF_H_
#define ARMOR_AND_DAMAGE_DEBUFF_H_

#include "../ParamChangeMagic.h"
#include "../Elements/ArmorReduceElem.h"
#include "../Elements/DamageReduceElem.h"

class ArmorAndDamageDebuffMagic
	: public ParamChangeMagic
{
public:
	using ParamChangeMagic::ParamChangeMagic;
	ArmorAndDamageDebuffMagic(std::string name, int manaCost,
		Time time, int armorReduce, int damageReduce);
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	~ArmorAndDamageDebuffMagic() = default;
};

#endif