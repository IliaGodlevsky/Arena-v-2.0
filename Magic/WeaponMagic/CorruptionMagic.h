#ifndef CORRUPTION_MAGIC_H_
#define CORRUPTION_MAGIC_H_

#include "../FreeParamChangeMagic.h"
#include "../../PossibilityCounter/PosibilityCounter.h"
#include "../Elements/ArmorReduceElem.h"

class CorruptionMagic : public FreeParamChangeMagic
{
public:
	CorruptionMagic(std::string name, Time time,
		ArmorReduceElem armorReduce, 
		PosibilityCounter propability);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit)override;
	MagicPtr clone()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	bool isDispelable()const override;
	~CorruptionMagic() = default;
private:
	ArmorReduceElem m_armorReduce;
	PosibilityCounter m_posibility;
};

#endif