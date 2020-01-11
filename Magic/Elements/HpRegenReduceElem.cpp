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