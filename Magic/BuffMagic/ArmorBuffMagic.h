#ifndef ARMOR_BUFF_H_
#define ARMOR_BUFF_H_

#include "../UnitParametresChangeMagic.h"
#include "../Elements/ArmorAmplifyElem.h"

class ArmorBuffMagic : public UnitParametresChangeMagic
{
public:
	using UnitParametresChangeMagic::UnitParametresChangeMagic;
	ArmorBuffMagic(std::string name, int manaCost,
		Time time, int armorAmplify);
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	~ArmorBuffMagic() = default;
};

#endif