#include "../../Unit/Unit.h"
#include "HpReduceElem.h"
#include "../../UnitState/InnerUnitState/DeadUnitState.h"

HpReduceElem::HpReduceElem(int hpReduce)
	:m_hpReduce(hpReduce)
{

}

void HpReduceElem::effectUnit(Unit& unit)
{
	unit.m_health = unit.m_health - m_hpReduce;
}

void HpReduceElem::showFullInfo()const
{
	std::cout << "Attack for " << m_hpReduce << " hp\n";
}

HpReduceElem::operator int()const
{
	return m_hpReduce;
}