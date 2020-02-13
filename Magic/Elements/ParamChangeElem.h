#ifndef PARAM_CHANGE_ELEM_H_
#define PARAM_CHANGE_ELEM_H_

#include "../../Globals/Globals.h"
#include "../Magic.h"

class ParamChangeElem;
using ParamChangeElemPtr = std::unique_ptr<ParamChangeElem>;

class ParamChangeElem
{
public:
	ParamChangeElem(int change);
	virtual void effectUnit(Unit& unit) = 0;
	virtual void uneffectUnit(Unit& unit) = 0;
	operator int()const;
	virtual bool isEqual(const ParamChangeElemPtr& element)const = 0;
	virtual ParamChangeElemPtr clone()const = 0;
	virtual ~ParamChangeElem() = default;
	virtual void showInfo()const = 0;
protected:
	int m_change = 0;
};
#endif
