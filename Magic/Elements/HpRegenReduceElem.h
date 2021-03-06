#ifndef HP_REGEN_REDUCE_ELEM_H_
#define HP_REGEN_REDUCE_ELEM_H_

#include "ParamChangeElem.h"

class HpRegenReduceElem : public ParamChangeElem
{
public:
	HpRegenReduceElem(int hpRegenReduce);
	void effectUnit(Unit& unit)override;
	void uneffectUnit(Unit& unit) override;
	bool isEqual(const ParamChangeElemPtr& element)const;
	ParamChangeElemPtr clone()const;
	void showInfo()const override;
	~HpRegenReduceElem() = default;
};
#endif
