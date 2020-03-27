#ifndef DAMAGE_DEBUFF_H_
#define DAMAGE_DEBUFF_H_

#include "../UnitParametresChangeMagic.h"
#include "../Elements/DamageReduceElem.h"

class DamageDebuffMagic : public UnitParametresChangeMagic
{
public:
	using UnitParametresChangeMagic::UnitParametresChangeMagic;
	DamageDebuffMagic(std::string name, int manaCost,
		Time time, int armorReduce);
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	~DamageDebuffMagic() = default;
};

#endif