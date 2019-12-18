#include "../../Unit/Unit.h"

#include "DamageDebuffMagic.h"


DamageDebuffMagic::DamageDebuffMagic(std::string name,
	int manaCost, int duration, int damageReduce)
	: Magic(name, manaCost, duration),
	m_damageReduce(damageReduce)
{

}

void DamageDebuffMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void DamageDebuffMagic::uneffectUnit(Unit& unit)const
{
	unit.m_damage.changeValue(m_damageReduce);
}

MagicPtr DamageDebuffMagic::clone()const
{
	return MagicPtr(new DamageDebuffMagic(m_name, m_manaCost, m_timer, m_damageReduce));
}

bool DamageDebuffMagic::isBuff()const
{
	return false;
}

bool DamageDebuffMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	DamageDebuffMagic* temp = DYNAMIC(DamageDebuffMagic*, magic);
	if (nullptr == temp)
		return false;
	return m_damageReduce == temp->m_damageReduce;
}

bool DamageDebuffMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void DamageDebuffMagic::putOn(Unit& unit)const
{
	unit.m_damage.changeValue(-m_damageReduce);
}

void DamageDebuffMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}

void DamageDebuffMagic::showData()const
{
	std::cout << "Damage reduce: " << m_damageReduce << std::endl;
}