#include "PoisonAndAttackMagic.h"

#include "../../Unit/Unit.h"

PoisonAndAttackMagic::PoisonAndAttackMagic(std::string name, int manaCost,
	Timer timer, HpReduceElem damage, HpRegenReduceElem regenReduce)
	: PoisonMagic(name, manaCost, timer, regenReduce), m_damage(damage)
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
		m_timer, m_damage, m_regenReduce));
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
	std::cout << "Damage: " << m_damage << std::endl;
}