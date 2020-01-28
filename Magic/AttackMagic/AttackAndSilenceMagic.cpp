#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/OuterUnitState/MutedUnitState.h"
#include "../../Arena/Arena.h"

#include "AttackAndSilenceMagic.h"

AttackAndSilenceMagic::AttackAndSilenceMagic(std::string name, int manaCost,
	Timer timer, int damage)
	: AttackMagic(name, manaCost, damage), m_silence(name, manaCost, timer),
	m_timer(timer)
{

}

void AttackAndSilenceMagic::effectUnit(Unit& unit)
{
	AttackMagic::effectUnit(unit);
	m_silence.effectUnit(unit);
}

MagicPtr AttackAndSilenceMagic::clone()const
{
	return MagicPtr(new AttackAndSilenceMagic(m_name, m_manaCost, m_timer, m_damage));
}

bool AttackAndSilenceMagic::isBuff()const
{
	return false;
}

bool AttackAndSilenceMagic::isEqual(const MagicPtr& magic)const
{
	return AttackMagic::isEqual(magic)
		&& canCast<AttackAndSilenceMagic*>(magic);
}

void AttackAndSilenceMagic::showFullInfo()const
{
	AttackMagic::showFullInfo();
	std::cout << "Mutes unit for " << m_timer.getDuration() << " rounds\n";
}

void AttackAndSilenceMagic::showShortInfo()const
{
	AttackMagic::showShortInfo();
}