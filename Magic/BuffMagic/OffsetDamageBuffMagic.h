#ifndef OFFSET_DAMAGE_BUFF_H_
#define OFFSET_DAMAGE_BUFF_H_

#include "../ParamChangeMagic.h"
#include "../Elements/DamageAmplifyElem.h"
#include "../Elements/ArmorReduceElem.h"

class OffsetDamageBuffMagic
	: public ParamChangeMagic
{
public:
	using ParamChangeMagic::ParamChangeMagic;
	OffsetDamageBuffMagic(std::string name, int manaCost,
		Time time, int armorReduce, int damageAmplify);
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	~OffsetDamageBuffMagic() = default;
};

#endif