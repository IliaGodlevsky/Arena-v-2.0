#ifndef MANA_REDUCE_MAGIC_H_
#define MANA_REDUCE_MAGIC_H_

#include "../Magic.h"
#include "../../Interface/Interface.h"
#include "../Elements/MpReduceElem.h"

class ManaReduceMagic : public Magic, public IBuff, public IManaCost
{
public:
	ManaReduceMagic(std::string name, int manaCost, MpReduceElem damage);
	virtual void effectUnit(Unit& unit) override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual int getCost()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual void showShortInfo()const override;
	virtual ~ManaReduceMagic() = default;
protected:
	int m_manaCost = 0;
	MpReduceElem m_mpReduce;
};

#endif
