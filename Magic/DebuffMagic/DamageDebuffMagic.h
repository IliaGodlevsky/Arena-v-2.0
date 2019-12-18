#ifndef DAMAGE_DEBUFF_H_
#define DAMAGE_DEBUFF_H_

#include "../../Globals/Globals.h"

#include "../Magic.h"

class DamageDebuffMagic : virtual public Magic
{
public:
	DamageDebuffMagic(std::string name, int manaCost, int duration,
		int damageReduce);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual ~DamageDebuffMagic() = default;
protected:
	int m_damageReduce;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
};

#endif