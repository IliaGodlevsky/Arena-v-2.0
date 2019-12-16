#include "DamageDebuff.h"
#include "Unit.h"

DamageDebuff::DamageDebuff(std::string name,
	int manaCost, int duration, int damageReduce)
	: Magic(name, manaCost, duration),
	m_damageReduce(damageReduce)
{

}

void DamageDebuff::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void DamageDebuff::uneffectUnit(Unit& unit)const
{
	unit.m_damage.changeValue(m_damageReduce);
}

MagicPtr DamageDebuff::clone()const
{
	return MagicPtr(new DamageDebuff(m_name, m_manaCost, m_durationmeter, m_damageReduce));
}

bool DamageDebuff::isBuff()const
{
	return false;
}

bool DamageDebuff::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	DamageDebuff* temp = DYNAMIC(DamageDebuff*, magic);
	if (nullptr == temp)
		return false;
	return m_damageReduce == temp->m_damageReduce;
}

bool DamageDebuff::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void DamageDebuff::putOn(Unit& unit)const
{
	unit.m_damage.changeValue(-m_damageReduce);
}

void DamageDebuff::showFullInfo()const
{
	Magic::showData();
	showData();
}

void DamageDebuff::showData()const
{
	std::cout << "Damage reduce: " << m_damageReduce << std::endl;
}