#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/StunUnitState.h"
#include "../../Arena/Arena.h"

#include "AttackAndStunMagic.h"


AttackAndStunMagic::AttackAndStunMagic(std::string name, int manaCost,
	Timer timer, int damage)
	: AttackMagic(name, manaCost, damage)
{

}

void AttackAndStunMagic::effectUnit(Unit& unit)
{
	AttackMagic::effectUnit(unit);
	unit.m_stateHolder.takeNew(StatePtr(new StunUnitState(Timer(m_timer.getDuration(), 
		Arena::getCurrentRound()))));
}

MagicPtr AttackAndStunMagic::clone()const
{
	return MagicPtr(new AttackAndStunMagic(m_name, m_manaCost, m_timer, m_damage));
}

bool AttackAndStunMagic::isBuff()const
{
	return false;
}

bool AttackAndStunMagic::isEqual(const MagicPtr& magic)const
{
	return AttackMagic::isEqual(magic) && canCast<AttackAndStunMagic*>(magic);
}

void AttackAndStunMagic::showFullInfo()const
{
	AttackMagic::showFullInfo();
	std::cout << "Stuns unit for " << m_timer.getDuration();
}

void AttackAndStunMagic::showShortInfo()const
{
	AttackMagic::showShortInfo();
}
