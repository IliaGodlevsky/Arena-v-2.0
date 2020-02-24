#ifndef DEGENERATE_MAGIC_H_
#define DEGENERATE_MAGIC_H_

#include "WeaponMagic.h"
#include "../Elements/HpRegenReduceElem.h"

class DegenerateMagic : public WeaponMagic
{
public:
	DegenerateMagic(std::string name, Time time,
		int hpRegenReduce, PosibilityCounter propability);
	DegenerateMagic(std::string name, Time time,
		const ElementHolder& elements, PosibilityCounter propability);
	MagicPtr clone()const override;
	bool isEqual(const MagicPtr& magic)const override;
	bool isDispelable()const override;
	~DegenerateMagic() = default;
};

#endif