#include "ArmorBuffMagic.h"

#include "../../Unit/Unit.h"


ArmorBuffMagic::ArmorBuffMagic(std::string name, int manaCost,
	int duration, int armorAmplify)
	: Magic(name, manaCost, duration),
	m_armorAmplify(armorAmplify)
{

}

void ArmorBuffMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void ArmorBuffMagic::uneffectUnit(Unit& unit)const
{
	unit.m_armor.changeValue(-m_armorAmplify);
}

MagicPtr ArmorBuffMagic::clone()const
{
	return MagicPtr(new ArmorBuffMagic(m_name, m_manaCost, m_timer, m_armorAmplify));
}

void ArmorBuffMagic::putOn(Unit& unit)const
{
	unit.m_armor.changeValue(m_armorAmplify);
}

bool ArmorBuffMagic::isBuff()const
{
	return true;
}

bool ArmorBuffMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	ArmorBuffMagic* temp = DYNAMIC(ArmorBuffMagic*, magic);
	if (nullptr == temp)
		return false;
	return m_armorAmplify == temp->m_armorAmplify;
}

bool ArmorBuffMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void ArmorBuffMagic::showData()const
{
	std::cout << "Armor add: " << m_armorAmplify << std::endl;
}

void ArmorBuffMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}