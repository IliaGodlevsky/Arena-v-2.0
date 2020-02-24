#ifndef CORRUPTION_MAGIC_H_
#define CORRUPTION_MAGIC_H_

#include "WeaponMagic.h"
#include "../Elements/ArmorReduceElem.h"

class CorruptionMagic : public WeaponMagic
{
public:
	CorruptionMagic(std::string name, Time time,
		int armorReduce, PosibilityCounter propability);
	CorruptionMagic(std::string name, Time time,
		const ElementHolder& elements, PosibilityCounter propability);
	MagicPtr clone()const override;
	bool isEqual(const MagicPtr& magic)const override;
	bool isDispelable()const override;
	~CorruptionMagic() = default;
};

#endif