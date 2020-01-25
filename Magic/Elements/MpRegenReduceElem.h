#ifndef MP_REGEN_REDUCE_ELEM_H_
#define MP_REGEN_REDUCE_ELEM_H_

#include "ParamChangeElem.h"

class MpRegenReduceElem : public ParamChangeElem
{
public:
	MpRegenReduceElem(int mpRegenReduce);
	void effectUnit(Unit& unit)override;
	void uneffectUnit(Unit& unit) override;
	~MpRegenReduceElem() = default;
};
#endif
