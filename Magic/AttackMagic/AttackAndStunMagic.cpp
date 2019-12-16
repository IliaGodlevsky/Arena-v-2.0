#include "AttackAndStunMagic.h"
#include "Unit.h"

AttackAndStunMagic::AttackAndStunMagic(std::string name, int manaCost,
	int duration, int damage)
	: Magic(name, manaCost, duration),
	AttackMagic(name, manaCost, damage)
{

}

void AttackAndStunMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	unit.recieveNewState(std::shared_ptr<UnitState>(new StunState(m_durationmeter)));
	AttackMagic::effectUnit(unit);
}

void AttackAndStunMagic::uneffectUnit(Unit& unit)const
{
	AttackMagic::uneffectUnit(unit);
}

MagicPtr AttackAndStunMagic::clone()const
{
	return MagicPtr(new AttackAndStunMagic(m_name, m_manaCost, m_durationmeter, m_damage));
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
	std::cout << "Stuns unit for " << m_durationmeter << " rounds\n";
}

void AttackAndStunMagic::putOn(Unit& unit)const
{
	AttackMagic::putOn(unit);
}
