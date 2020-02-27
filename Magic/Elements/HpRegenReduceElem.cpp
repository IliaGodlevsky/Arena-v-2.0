#include "HpRegenReduceElem.h"

#include "../../Unit/Unit.h"

HpRegenReduceElem::HpRegenReduceElem(int hpRegenReduce)
	:ParamChangeElem(hpRegenReduce)
{

}

void HpRegenReduceElem::effectUnit(Unit& unit)
{
	unit.m_health.changeRegeneration(-m_change);
}

void HpRegenReduceElem::uneffectUnit(Unit& unit)
{
	unit.m_health.changeRegeneration(m_change);
}

bool HpRegenReduceElem::isEqual(const ParamChangeElemPtr& element)const
{
	return canCast<HpRegenReduceElem*>(element)
		&& ParamChangeElem::isEqual(element);
}

ParamChangeElemPtr HpRegenReduceElem::clone()const
{
	return ParamChangeElemPtr(new HpRegenReduceElem(m_change));
}

void HpRegenReduceElem::showInfo()const
{
	std::cout << "Reduces regen by " << m_change;
}