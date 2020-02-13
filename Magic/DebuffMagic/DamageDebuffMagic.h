#ifndef DAMAGE_DEBUFF_H_
#define DAMAGE_DEBUFF_H_

#include "../ParamChangeMagic.h"
#include "../Elements/DamageReduceElem.h"

class DamageDebuffMagic : public ParamChangeMagic
{
public:
	using ParamChangeMagic::ParamChangeMagic;
	DamageDebuffMagic(std::string name, int manaCost,
		Time time, int armorReduce);
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	~DamageDebuffMagic() = default;
};

#endif