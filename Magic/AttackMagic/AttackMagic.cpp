#include "..//../Unit/Unit.h"

#include "AttackMagic.h"

AttackMagic::AttackMagic(std::string name, int manaCost, HpReduceElem damage)
	: Magic(name), m_damage(damage), IManaCost(manaCost)
{

}

void AttackMagic::effectUnit(Unit& unit)
{
	m_damage.effectUnit(unit);
}

MagicPtr AttackMagic::clone()const
{
	return MagicPtr(new AttackMagic(m_name, m_manaCost, m_damage));
}

bool AttackMagic::isBuff()const
{
	return false;
}

bool AttackMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<AttackMagic*>(magic))
		return false;
	const auto temp = dCast<AttackMagic*>(magic);
	return Magic::isEqual(magic) &&
		temp->m_damage == m_damage && 
		m_manaCost == temp->m_manaCost;
}

void AttackMagic::showFullInfo()const
{
	Magic::showFullInfo();
	std::cout << "Deals " << m_damage << " damage\n";
}

void AttackMagic::showShortInfo()const
{
	std::cout << "<";
	Magic::showShortInfo();
	std::cout << ": " << m_manaCost << "> ";
}