#ifndef DEGENERATE_MAGIC_H_
#define DEGENERATE_MAGIC_H_

#include "../../PossibilityCounter/PosibilityCounter.h"
#include "../Elements/HpRegenReduceElem.h"
#include "../FreeParamChangeMagic.h"

class DegenerateMagic : public FreeParamChangeMagic
{
public:
	DegenerateMagic(std::string name, Time time,
		int armorReduce, PosibilityCounter propability);
	DegenerateMagic(std::string name, Time time,
		const ElementHolder& elements, PosibilityCounter propability);
	void effectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isEqual(const MagicPtr& magic)const override;
	bool isDispelable()const override;
	~DegenerateMagic() = default;
private:
	PosibilityCounter m_posibility;
};

#endif