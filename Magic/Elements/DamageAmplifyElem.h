#ifndef DAMAGE_AMPLIFY_ELEM_H_
#define DAMAGE_AMPLIFY_ELEM_H_

#include "ParamChangeElem.h"

class DamageAmplifyElem : public ParamChangeElem
{
public:
	DamageAmplifyElem(int damageAmplify);
	void effectUnit(Unit& unit)override;
	void uneffectUnit(Unit& unit)override;
	bool isEqual(const ParamChangeElemPtr& element)const;
	ParamChangeElemPtr clone()const;
	void showInfo()const override;
	~DamageAmplifyElem() = default;
};
#endif