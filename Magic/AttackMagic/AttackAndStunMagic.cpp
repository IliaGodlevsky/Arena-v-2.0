#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/OuterUnitState/StunUnitState.h"
#include "../../Arena/Arena.h"

#include "AttackAndStunMagic.h"


AttackAndStunMagic::AttackAndStunMagic(std::string name, int manaCost,
	int duration, int damage)
	: AttackMagic(name, manaCost, damage), m_duration(duration)
{

}

void AttackAndStunMagic::effectUnit(Unit& unit)
{
	AttackMagic::effectUnit(unit);
	unit.m_stateHolder.takeNew(StatePtr(new StunUnitState({ m_duration,
		Arena::getCurrentRound() })));
}

MagicPtr AttackAndStunMagic::clone()const
{
	return MagicPtr(new AttackAndStunMagic(m_name, m_manaCost, m_duration, m_damage));
}

bool AttackAndStunMagic::isBuff()const
{
	return false;
}

bool AttackAndStunMagic::isEqual(const MagicPtr& magic)const
{
	return AttackMagic::isEqual(magic) && 
		canCast<AttackAndStunMagic*>(magic);
}

void AttackAndStunMagic::showFullInfo()const
{
	AttackMagic::showFullInfo();
	std::cout << "Stuns unit for " << m_duration << " rounds\n";
}

void AttackAndStunMagic::showShortInfo()const
{
	AttackMagic::showShortInfo();
}
