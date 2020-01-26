#include "..//../Unit/Unit.h"

#include "ManaReduceMagic.h"

ManaReduceMagic::ManaReduceMagic(std::string name, int manaCost, MpReduceElem damage)
	:Magic(name), m_manaCost(manaCost), m_mpReduce(damage)
{

}

void ManaReduceMagic::effectUnit(Unit& unit)
{
	m_mpReduce.effectUnit(unit);
}

MagicPtr ManaReduceMagic::clone()const
{
	return MagicPtr(new ManaReduceMagic(m_name, m_manaCost, m_mpReduce));
}

bool ManaReduceMagic::isBuff()const
{
	return false;
}

int ManaReduceMagic::getCost()const
{
	return m_manaCost;
}

bool ManaReduceMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<ManaReduceMagic*>(magic))
		return false;
	ManaReduceMagic* temp = DYNAMIC(ManaReduceMagic*, magic);
	return Magic::isEqual(magic) &&
		temp->m_mpReduce == m_mpReduce &&
		m_manaCost == temp->m_manaCost;
}

void ManaReduceMagic::showFullInfo()const
{
	
}

void ManaReduceMagic::showShortInfo()const
{
	std::cout << "<";
	Magic::showShortInfo();
	std::cout << ": " << m_manaCost << "> ";
}