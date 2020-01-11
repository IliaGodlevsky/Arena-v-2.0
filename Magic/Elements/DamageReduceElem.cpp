#include "../../Unit/Unit.h"
#include "DamageReduceElem.h"

DamageReduceElem::DamageReduceElem(int damageReduce)
	: ParamChangeElem(damageReduce)
{

}

void DamageReduceElem::effectUnit(Unit& unit)
{
	unit.m_damage.changeValue(-m_change);
}

void DamageReduceElem::uneffectUnit(Unit& unit)
{
	unit.m_damage.changeValue(m_change);
}