#ifndef DEGENERATE_MAGIC_H_
#define DEGENERATE_MAGIC_H_

#include "../../PossibilityCounter/PosibilityCounter.h"
#include "../Elements/HpRegenReduceElem.h"
#include "../FreeParamChangeMagic.h"

class DegenerateMagic : public FreeParamChangeMagic
{
public:
	DegenerateMagic(std::string name, Timer timer,
		HpRegenReduceElem armorReduce,
		PosibilityCounter propability);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit)override;
	MagicPtr clone()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	bool isDispelable()const override;
	~DegenerateMagic() = default;
private:
	HpRegenReduceElem m_regenReduce;
	PosibilityCounter m_posibility;
};

#endif