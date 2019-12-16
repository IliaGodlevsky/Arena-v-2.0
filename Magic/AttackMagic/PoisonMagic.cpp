#include "PoisonMagic.h"
#include "Unit.h"

PoisonMagic::PoisonMagic(std::string name, int manaCost, int duration,
	int regenReduce)
	: Magic(name, manaCost, duration), m_regenReduce(regenReduce)
{

}

void PoisonMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void PoisonMagic::uneffectUnit(Unit& unit)const
{
	unit.m_health.changeRegeneration(m_regenReduce);
}

MagicPtr PoisonMagic::clone()const
{
	return MagicPtr(new PoisonMagic(m_name, m_manaCost, m_durationmeter, m_regenReduce));
}

bool PoisonMagic::isBuff()const
{
	return false;
}

bool PoisonMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	PoisonMagic* temp = DYNAMIC(PoisonMagic*, magic);
	if (nullptr == temp)
		return false;
	return m_regenReduce == temp->m_regenReduce;
}

bool PoisonMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void PoisonMagic::putOn(Unit& unit)const
{
	unit.m_health.changeRegeneration(-m_regenReduce);
}

void PoisonMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}

void PoisonMagic::showData()const
{
	std::cout << "Deals " << m_regenReduce << " per round\n";
}