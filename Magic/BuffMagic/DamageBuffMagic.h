#ifndef DAMAGE_BUFF_H_
#define DAMAGE_BUFF_H_

#include "../UnitParametresChangeMagic.h"
#include "../Elements/DamageAmplifyElem.h"

class DamageBuffMagic : public UnitParametresChangeMagic
{
public:
	using UnitParametresChangeMagic::UnitParametresChangeMagic;
	DamageBuffMagic(std::string name, int manaCost,
		Time time, int armorAmplify);
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	~DamageBuffMagic() = default;
};

#endif