#ifndef POISON_H_
#define POISON_H_

#include "../../Globals/Globals.h"

#include "../Magic.h"

class PoisonMagic : virtual public Magic
{
public:
	PoisonMagic(std::string name, int manaCost, int duration,
		int regenReduce);
	virtual void effectUnit(Unit& unit) override;
	virtual void uneffectUnit(Unit& unit)const override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual ~PoisonMagic() = default;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const override;
	virtual void showData()const override;
	virtual void putOn(Unit& unit)const override;
protected:
	int m_regenReduce;
};
#endif