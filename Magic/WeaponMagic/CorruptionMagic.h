#ifndef CORRUPTION_MAGIC_H_
#define CORRUPTION_MAGIC_H_

#include "../../Magic/DebuffMagic/ArmorDebuffMagic.h"
#include "../../PossibilityCounter/PosibilityCounter.h"

class CorruptionMagic : public ArmorDebuffMagic
{
public:
	CorruptionMagic(std::string name, const Timer& timer,
		int armorReduce, PosibilityCounter propability);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const override;
protected:
	PosibilityCounter m_posibility;
};

#endif