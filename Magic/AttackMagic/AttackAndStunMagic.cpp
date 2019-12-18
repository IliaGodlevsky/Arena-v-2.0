#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"
#include "../../UnitState/StunUnitState.h"

#include "AttackAndStunMagic.h"


AttackAndStunMagic::AttackAndStunMagic(std::string name, int manaCost,
	int duration, int damage)
	: Magic(name, manaCost, duration),
	AttackMagic(name, manaCost, damage)
{

}

void AttackAndStunMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	unit.recieveNewState(StatePtr(new StunUnitState(m_timer)));
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
	if (nullptr == magic)
		return false;
	AttackAndStunMagic* temp = DYNAMIC(AttackAndStunMagic*, magic);
	if (nullptr == temp)
		return false;
	return AttackMagic::hasEqualParametres(magic);
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
	std::cout << "Stuns unit for " << m_timer << " rounds\n";
}

void AttackAndStunMagic::putOn(Unit& unit)const
{
	AttackMagic::putOn(unit);
}
