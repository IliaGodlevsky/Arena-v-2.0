#include "ArmorBuff.h"
#include "Unit.h"

ArmorBuff::ArmorBuff(std::string name, int manaCost,
	int duration, int armorAmplify)
	: Magic(name, manaCost, duration),
	m_armorAmplify(armorAmplify)
{

}

void ArmorBuff::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void ArmorBuff::uneffectUnit(Unit& unit)const
{
	unit.m_armor.changeValue(-m_armorAmplify);
}

MagicPtr ArmorBuff::clone()const
{
	return MagicPtr(new ArmorBuff(m_name, m_manaCost, m_durationmeter, m_armorAmplify));
}

void ArmorBuff::putOn(Unit& unit)const
{
	unit.m_armor.changeValue(m_armorAmplify);
}

bool ArmorBuff::isBuff()const
{
	return true;
}

bool ArmorBuff::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	ArmorBuff* temp = DYNAMIC(ArmorBuff*, magic);
	if (nullptr == temp)
		return false;
	return m_armorAmplify == temp->m_armorAmplify;
}

bool ArmorBuff::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void ArmorBuff::showData()const
{
	std::cout << "Armor add: " << m_armorAmplify << std::endl;
}

void ArmorBuff::showFullInfo()const
{
	Magic::showData();
	showData();
}