#include "ArmorDebuff.h"
#include "Unit.h"

ArmorDebuff::ArmorDebuff(std::string name, int manaCost,
	int duration, int armorReduce)
	: Magic(name, manaCost, duration),
	m_armorReduce(armorReduce)
{

}

void ArmorDebuff::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void ArmorDebuff::uneffectUnit(Unit& unit)const
{
	unit.m_armor.changeValue(m_armorReduce);
}

MagicPtr ArmorDebuff::clone()const
{
	return MagicPtr(new ArmorDebuff(m_name, m_manaCost,
		m_durationmeter, m_armorReduce));
}

bool ArmorDebuff::isBuff()const
{
	return false;
}

bool ArmorDebuff::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	ArmorDebuff* temp = DYNAMIC(ArmorDebuff*, magic);
	if (nullptr == temp)
		return false;
	return m_armorReduce == temp->m_armorReduce;
}

bool ArmorDebuff::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void ArmorDebuff::putOn(Unit& unit)const
{
	unit.m_armor.changeValue(-m_armorReduce);
}

void ArmorDebuff::showFullInfo()const
{
	Magic::showData();
	showData();
}

void ArmorDebuff::showData()const
{
	std::cout << "Armor reduce: " << m_armorReduce << std::endl;
}