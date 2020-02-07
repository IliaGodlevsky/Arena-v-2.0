#include "AttackMissChanceMagic.h"
#include "../../UnitState/OuterUnitState/MissAttackUnitState.h"
#include "../../Unit/Unit.h"

AttackMissChanceMagic::AttackMissChanceMagic(std::string name,
	int missChance, int manaCost, int duration) : Magic(name), m_missChance(missChance),
	IManaCost(manaCost), m_duration(duration)
{

}

MagicPtr AttackMissChanceMagic::clone()const
{
	return MagicPtr(new AttackMissChanceMagic(m_name, m_missChance, m_manaCost, m_duration));
}

bool AttackMissChanceMagic::isBuff()const
{
	return false;
}

void AttackMissChanceMagic::effectUnit(Unit& unit)
{
	unit.m_stateHolder.takeNew(StatePtr(new MissAttackUnitState({ m_duration,
		Arena::getCurrentRound() }, PosibilityCounter(m_missChance))));
}

bool AttackMissChanceMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<AttackMissChanceMagic*>(magic))
		return false;
	AttackMissChanceMagic* temp = DYNAMIC(AttackMissChanceMagic*, magic);
	return Magic::isEqual(magic) &&
		temp->m_duration == m_duration && 
		temp->m_missChance == m_missChance &&
		temp->m_manaCost == m_manaCost;
}

void AttackMissChanceMagic::showFullInfo()const
{
	std::cout << " Enemy misses attack with " << m_missChance
		<< " posibilty for " << m_duration << " rounds\n";
}

void AttackMissChanceMagic::showShortInfo()const
{
	std::cout << "<";
	Magic::showShortInfo();
	std::cout << ": " << m_manaCost << "> ";
}