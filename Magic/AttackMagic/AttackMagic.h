#ifndef ATTACK_MAGIC_H_
#define ATTACK_MAGIC_H_

#include "../Magic.h"
#include "../../Interface/Interface.h"
#include "../Elements/HpReduceElem.h"

class AttackMagic : public Magic, public IBuff, public IManaCost
{
public:
	AttackMagic(std::string name, int manaCost, HpReduceElem damage);
	virtual void effectUnit(Unit& unit) override;
	virtual MagicPtr clone()const override;
	virtual bool isBuff()const override;
	virtual int getCost()const override;
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual void showShortInfo()const override;
	virtual ~AttackMagic() = default;
protected:
	int m_manaCost = 0;
	HpReduceElem m_damage;
};

#endif