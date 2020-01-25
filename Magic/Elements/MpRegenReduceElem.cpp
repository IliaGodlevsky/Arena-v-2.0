#include "MpRegenReduceElem.h"

#include "../../Unit/Unit.h"

MpRegenReduceElem::MpRegenReduceElem(int mpRegenReduce)
	: ParamChangeElem(mpRegenReduce)
{

}

void MpRegenReduceElem::effectUnit(Unit& unit)
{
	unit.m_mana.changeRegeneration(-m_change);
}

void MpRegenReduceElem::uneffectUnit(Unit& unit)
{
	unit.m_mana.changeRegeneration(m_change);
}