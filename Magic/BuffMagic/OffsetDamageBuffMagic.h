#ifndef OFFSET_DAMAGE_BUFF_H_
#define OFFSET_DAMAGE_BUFF_H_

#include "../UnitParametresChangeMagic.h"
#include "../Elements/DamageAmplifyElem.h"
#include "../Elements/ArmorReduceElem.h"

class OffsetDamageBuffMagic
	: public UnitParametresChangeMagic
{
public:
	using UnitParametresChangeMagic::UnitParametresChangeMagic;
	OffsetDamageBuffMagic(std::string name, int manaCost,
		Time time, int armorReduce, int damageAmplify);
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	~OffsetDamageBuffMagic() = default;
};

#endif