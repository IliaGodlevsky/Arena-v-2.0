#include "MpReduceElem.h"

#include "../../Unit/Unit.h"

MpReduceElem::MpReduceElem(int mpReduce)
	: m_mpReduce(mpReduce)
{

}

void MpReduceElem::effectUnit(Unit& unit)
{
	unit.m_mana = unit.m_mana - m_mpReduce;
}

MpReduceElem::operator int()const
{
	return m_mpReduce;
}