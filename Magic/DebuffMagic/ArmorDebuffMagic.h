#ifndef ARMOR_DEBUFF_H_
#define ARMOR_DEBUFF_H_

#include "../../Globals/Globals.h"

#include "../Magic.h"

class ArmorDebuffMagic : virtual public Magic
{
public:
	ArmorDebuffMagic(std::string name, int manaCost, int duration,
		int armorReduce);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual ~ArmorDebuffMagic() = default;
protected:
	int m_armorReduce;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
};

#endif