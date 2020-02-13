#ifndef DAMAGE_REDUCE_ELEM_H_
#define DAMAGE_REDUCE_ELEM_H_

#include "ParamChangeElem.h"

class DamageReduceElem : public ParamChangeElem
{
public:
	DamageReduceElem(int damageReduce);
	void effectUnit(Unit& unit)override;
	void uneffectUnit(Unit& unit)override;
	bool isEqual(const ParamChangeElemPtr& element)const;
	ParamChangeElemPtr clone()const;
	void showInfo()const override;
	~DamageReduceElem() = default;
};
#endif
