#ifndef ARMOR_AMPLIFY_ELEM_H_
#define ARMOR_AMPLIFY_ELEM_H_

#include "ParamChangeElem.h"

class ArmorAmplifyElem : public ParamChangeElem
{
public:
	ArmorAmplifyElem(int armorAmplify);
	void effectUnit(Unit& unit)override;
	void uneffectUnit(Unit& unit)override;
	~ArmorAmplifyElem() = default;
};
#endif
