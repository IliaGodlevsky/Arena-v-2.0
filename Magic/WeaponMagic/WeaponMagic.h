#ifndef WEAPON_MAGIC_H_
#define WEAPON_MAGIC_H_

#include "../../PossibilityCounter/PosibilityCounter.h"

#include "../Magic.h"

class WeaponMagic : public Magic
{
public:
	WeaponMagic(std::string name, int duration, 
		int propability);
	virtual void showFullInfo()const = 0;
	virtual ~WeaponMagic();
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override= 0;
	virtual bool isEqual(const MagicPtr& magic)const override = 0;
	virtual bool isCastChance()const final;
	virtual void showData()const = 0;
protected:
	int m_propability; // chance to be casted
};
#endif