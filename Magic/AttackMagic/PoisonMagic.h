#ifndef POISON_H_
#define POISON_H_

#include "../ParamChangeMagic.h"
#include "../Elements/HpRegenReduceElem.h"


class PoisonMagic : public ParamChangeMagic
{
public:
	using ParamChangeMagic::ParamChangeMagic;
	PoisonMagic(std::string name, int manaCost,
		Time time, int m_regenReduce);
	MagicPtr clone()const override;
	bool isBuff()const override;
	bool isDispelable()const override;
	bool isEqual(const MagicPtr& magic)const override;
	~PoisonMagic() = default;
};
#endif