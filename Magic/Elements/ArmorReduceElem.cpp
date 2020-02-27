#include "../../Unit/Unit.h"
#include "ArmorReduceElem.h"

ArmorReduceElem::ArmorReduceElem(int armorReduce)
	: ParamChangeElem(armorReduce)
{

}

void ArmorReduceElem::uneffectUnit(Unit& unit)
{
	unit.m_armor.changeAdditaionalValue(m_change);
}

void ArmorReduceElem::effectUnit(Unit& unit)
{
	unit.m_armor.changeAdditaionalValue(-m_change);
}

bool ArmorReduceElem::isEqual(const ParamChangeElemPtr& element)const
{
	return canCast<ArmorReduceElem*>(element)
		&& ParamChangeElem::isEqual(element);
}

ParamChangeElemPtr ArmorReduceElem::clone()const
{
	return ParamChangeElemPtr(new ArmorReduceElem(m_change));
}

void ArmorReduceElem::showInfo()const
{
	std::cout << "Reduces enemy armor by " << m_change;
}