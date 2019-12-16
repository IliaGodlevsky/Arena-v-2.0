#include "DamageBuff.h"
#include "Unit.h"

DamageBuff::DamageBuff(std::string name, int manaCost,
	int duration, int damageAmplify)
	: Magic(name, manaCost, duration),
	m_damageAmplify(damageAmplify)
{

}

void DamageBuff::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void DamageBuff::uneffectUnit(Unit& unit)const
{
	unit.m_damage.changeValue(-m_damageAmplify);
}

MagicPtr DamageBuff::clone()const
{
	return MagicPtr(new DamageBuff(m_name, m_manaCost, m_durationmeter, m_damageAmplify));
}

void DamageBuff::putOn(Unit& unit)const
{
	unit.m_damage.changeValue(m_damageAmplify);
}

bool DamageBuff::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	DamageBuff* temp = DYNAMIC(DamageBuff*, magic);
	if (nullptr == temp)
		return false;
	return m_damageAmplify == temp->m_damageAmplify;
}

bool DamageBuff::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

bool DamageBuff::isBuff()const
{
	return true;
}

void DamageBuff::showData()const
{
	std::cout << "Damage add: " << m_damageAmplify << std::endl;
}

void DamageBuff::showFullInfo()const
{
	Magic::showData();
	showData();
}