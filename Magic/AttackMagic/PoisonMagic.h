#ifndef POISON_H_
#define POISON_H_

#include "../ParamChangeMagic.h"
#include "../Elements/HpRegenReduceElem.h"


class PoisonMagic : public ParamChangeMagic
{
public:
	PoisonMagic(std::string name, int manaCost,
		Time time, HpRegenReduceElem m_regenReduce);
	void effectUnit(Unit& unit) override;
	void uneffectUnit(Unit& unit) override;
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	~PoisonMagic() = default;
protected:
	HpRegenReduceElem m_regenReduce;
};
#endif