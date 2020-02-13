#include "../../Unit/Unit.h"
#include "DamageReduceElem.h"

DamageReduceElem::DamageReduceElem(int damageReduce)
	: ParamChangeElem(damageReduce)
{

}

void DamageReduceElem::effectUnit(Unit& unit)
{
	unit.m_damage.changeAdditaionalValue(-m_change);
}

void DamageReduceElem::uneffectUnit(Unit& unit)
{
	unit.m_damage.changeAdditaionalValue(m_change);
}

bool DamageReduceElem::isEqual(const ParamChangeElemPtr& element)const
{
	if (!canCast<DamageReduceElem*>(element))
		return false;
	return ParamChangeElem::isEqual(element);
}

ParamChangeElemPtr DamageReduceElem::clone()const
{
	return ParamChangeElemPtr(new DamageReduceElem(m_change));
}

void DamageReduceElem::showInfo()const
{
	std::cout << "Reduces enemy damage by " << m_change;
}