#ifndef CORRUPTION_MAGIC_H_
#define CORRUPTION_MAGIC_H_

#include "WeaponMagic.h"

class CorruptionMagic : public WeaponMagic
{
public:
	CorruptionMagic(std::string name, int duration,
		int armorReduce, int propability);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
protected:
	int m_armorReduce;
};

#endif