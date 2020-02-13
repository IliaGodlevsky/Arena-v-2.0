#ifndef ARMOR_REDUCE_ELEM_H_
#define ARMOR_REDUCE_ELEM_H_

#include "ParamChangeElem.h"

class ArmorReduceElem : public ParamChangeElem
{
public:
	ArmorReduceElem(int armorReduce);
	void uneffectUnit(Unit& unit)override;
	void effectUnit(Unit& unit) override;
	bool isEqual(const ParamChangeElemPtr& element)const;
	ParamChangeElemPtr clone()const;
	void showInfo()const override;
	~ArmorReduceElem() = default;
};
#endif
