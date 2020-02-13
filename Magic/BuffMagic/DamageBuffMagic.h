#ifndef DAMAGE_BUFF_H_
#define DAMAGE_BUFF_H_

#include "../ParamChangeMagic.h"
#include "../Elements/DamageAmplifyElem.h"

class DamageBuffMagic : public ParamChangeMagic
{
public:
	using ParamChangeMagic::ParamChangeMagic;
	DamageBuffMagic(std::string name, int manaCost,
		Time time, int armorAmplify);
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	~DamageBuffMagic() = default;
};

#endif