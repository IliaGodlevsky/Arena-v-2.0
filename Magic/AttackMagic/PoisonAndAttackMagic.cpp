#include "PoisonAndAttackMagic.h"

#include "../../Unit/Unit.h"

PoisonAndAttackMagic::PoisonAndAttackMagic(std::string name, int manaCost,
	Time time, HpReduceElem damage, int regenReduce)
	: PoisonMagic(name, manaCost, time, regenReduce), m_damage(damage)
{

}

PoisonAndAttackMagic::PoisonAndAttackMagic(std::string name,
	int manaCost, Time time, HpReduceElem damage, const ElementHolder& elements)
	: PoisonMagic(name, manaCost, time, elements), m_damage(damage)
{

}

void PoisonAndAttackMagic::effectUnit(Unit& unit)
{
	PoisonMagic::effectUnit(unit);
	m_damage.effectUnit(unit);
}

MagicPtr PoisonAndAttackMagic::clone()const
{
	return MagicPtr(new PoisonAndAttackMagic(m_name, m_manaCost,
		m_time, m_damage, m_elemHolder));
}

bool PoisonAndAttackMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<PoisonAndAttackMagic*>(magic))
		return false;
	PoisonAndAttackMagic* temp = DYNAMIC(PoisonAndAttackMagic*, magic);
	return PoisonMagic::isEqual(magic)
		&& m_damage == temp->m_damage;
}

void PoisonAndAttackMagic::showFullInfo()const
{
	PoisonMagic::showFullInfo();
	std::cout << "Deals: " << m_damage << " damage\n";
}