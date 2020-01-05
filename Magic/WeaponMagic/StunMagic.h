#ifndef STUN_MAGIC_H_
#define STUN_MAGIC_H_

#include "../Magic.h"
#include "../../PossibilityCounter/PosibilityCounter.h"

class StunMagic : virtual public Magic
{
public:
	StunMagic(std::string name, const Timer& timer, 
		PosibilityCounter propability);
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
private:
	PosibilityCounter m_posibility;
};

#endif