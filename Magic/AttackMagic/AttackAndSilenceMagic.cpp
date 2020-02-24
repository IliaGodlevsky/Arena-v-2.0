#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/OuterUnitState/MutedUnitState.h"
#include "../../Arena/Arena.h"

#include "AttackAndSilenceMagic.h"

AttackAndSilenceMagic::AttackAndSilenceMagic(std::string name, int manaCost,
	int duration, int damage)
	: AttackMagic(name, manaCost, damage), m_silence(name, manaCost, duration),
	m_duration(duration)
{

}

void AttackAndSilenceMagic::effectUnit(Unit& unit)
{
	AttackMagic::effectUnit(unit);
	m_silence.effectUnit(unit);
}

MagicPtr AttackAndSilenceMagic::clone()const
{
	return MagicPtr(new AttackAndSilenceMagic(m_name, m_manaCost, m_duration, m_damage));
}

bool AttackAndSilenceMagic::isBuff()const
{
	return false;
}

bool AttackAndSilenceMagic::isEqual(const MagicPtr& magic)const
{
	return ::isEqual<AttackAndSilenceMagic*, AttackMagic>(magic);
}

void AttackAndSilenceMagic::showFullInfo()const
{
	AttackMagic::showFullInfo();
	std::cout << "Mutes unit for " << m_duration << " rounds\n";
}

void AttackAndSilenceMagic::showShortInfo()const
{
	AttackMagic::showShortInfo();
}