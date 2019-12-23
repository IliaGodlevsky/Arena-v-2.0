#include "..//../Unit/Unit.h"

#include "AttackMagic.h"

AttackMagic::AttackMagic(std::string name, int manaCost, int damage)
	: Magic(name, manaCost, Timer(0)), m_damage(damage)
{

}

void AttackMagic::effectUnit(Unit& unit)
{
	unit.m_health = unit.m_health - m_damage;
}

void AttackMagic::uneffectUnit(Unit& unit)const
{
	return;
}

MagicPtr AttackMagic::clone()const
{
	return MagicPtr(new AttackMagic(m_name, m_manaCost, m_damage));
}

bool AttackMagic::isBuff()const
{
	return false;
}

bool AttackMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	AttackMagic* temp = DYNAMIC(AttackMagic*, magic);
	if (nullptr == temp)
		return false;
	return m_damage == temp->m_damage;
}

bool AttackMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void AttackMagic::putOn(Unit& unit)const
{
	return;
}

void AttackMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}

void AttackMagic::showData()const
{
	std::cout << "Deals " << m_damage << std::endl;
}