#include "../../Unit/Unit.h"
#include "ArmorReduceElem.h"

ArmorReduceElem::ArmorReduceElem(int armorReduce)
	: ParamChangeElem(armorReduce)
{

}

void ArmorReduceElem::uneffectUnit(Unit& unit)
{
	unit.m_armor.changeValue(-m_change);
}

void ArmorReduceElem::effectUnit(Unit& unit)
{
	unit.m_armor.changeValue(m_change);
}