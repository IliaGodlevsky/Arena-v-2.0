#ifndef CORRUPTION_MAGIC_H_
#define CORRUPTION_MAGIC_H_

#include "../FreeParamChangeMagic.h"
#include "../../PossibilityCounter/PosibilityCounter.h"
#include "../Elements/ArmorReduceElem.h"

class CorruptionMagic : public FreeParamChangeMagic
{
public:
	CorruptionMagic(std::string name, Time time,
		int armorReduce, PosibilityCounter propability);
	CorruptionMagic(std::string name, Time time,
		const ElementHolder& elements, PosibilityCounter propability);
	void effectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isEqual(const MagicPtr& magic)const override;
	bool isDispelable()const override;
	~CorruptionMagic() = default;
	PosibilityCounter m_posibility;
};

#endif