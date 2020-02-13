#ifndef ARMOR_DEBUFF_H_
#define ARMOR_DEBUFF_H_

#include "../ParamChangeMagic.h"
#include "../Elements/ArmorReduceElem.h"

class ArmorDebuffMagic : public ParamChangeMagic
{
public:
	using ParamChangeMagic::ParamChangeMagic;
	ArmorDebuffMagic(std::string name, int manaCost,
		Time time, int armorReduce);
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	~ArmorDebuffMagic() = default;
};

#endif