#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/StunUnitState.h"
#include "../../Arena/Arena.h"

#include "AttackAndStunMagic.h"


AttackAndStunMagic::AttackAndStunMagic(std::string name, int manaCost,
	const Timer& timer, int damage)
	: Magic(name, manaCost, timer),
	AttackMagic(name, manaCost, damage),
	StunMagic(name, timer, PosibilityCounter(0))
{

}

void AttackAndStunMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	AttackMagic::effectUnit(unit);
}

void AttackAndStunMagic::uneffectUnit(Unit& unit)const
{
	AttackMagic::uneffectUnit(unit);
}

MagicPtr AttackAndStunMagic::clone()const
{
	return MagicPtr(new AttackAndStunMagic(m_name, m_manaCost, m_timer, m_damage));
}

bool AttackAndStunMagic::isBuff()const
{
	return false;
}

bool AttackAndStunMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (!canCast<AttackAndStunMagic*>(magic))
		return false;
	return AttackMagic::hasEqualParametres(magic) &&
		StunMagic::hasEqualParametres(magic);
}

bool AttackAndStunMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void AttackAndStunMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}

void AttackAndStunMagic::showData()const
{
	AttackMagic::showData();
	StunMagic::showData();
}

void AttackAndStunMagic::putOn(Unit& unit)const
{
	AttackMagic::putOn(unit);
	StunMagic::putOn(unit);
}

void AttackAndStunMagic::setStartTime(int round)
{
	if (round < Arena::getCurrentRound())
		round = Arena::getCurrentRound();
	m_timer.setStartTime(round);
}
