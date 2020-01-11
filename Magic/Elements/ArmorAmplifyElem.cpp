#include "ArmorAmplifyElem.h"
#include "../../Unit/Unit.h"

ArmorAmplifyElem::ArmorAmplifyElem(int armorAmplify)
	: ParamChangeElem(armorAmplify)
{

}

void ArmorAmplifyElem::effectUnit(Unit& unit)
{
	unit.m_armor.changeValue(m_change);
}

void ArmorAmplifyElem::uneffectUnit(Unit& unit)
{
	unit.m_armor.changeValue(-m_change);
}