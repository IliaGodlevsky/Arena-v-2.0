#ifndef PARAM_CHANGE_ELEM_H_
#define PARAM_CHANGE_ELEM_H_

#include "../../Globals/Globals.h"

class ParamChangeElem
{
public:
	ParamChangeElem(int change);
	virtual void effectUnit(Unit& unit) = 0;
	virtual void uneffectUnit(Unit& unit) = 0;
	operator int()const;
	virtual ~ParamChangeElem() = default;
protected:
	int m_change = 0;
};
#endif
