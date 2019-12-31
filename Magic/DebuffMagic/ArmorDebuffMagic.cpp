#include "../../Unit/Unit.h"

#include "ArmorDebuffMagic.h"


ArmorDebuffMagic::ArmorDebuffMagic(std::string name, int manaCost,
	const Timer& timer, int armorReduce)
	: Magic(name, manaCost, timer), 
	m_armorReduce(armorReduce)
{

}

void ArmorDebuffMagic::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void ArmorDebuffMagic::uneffectUnit(Unit& unit)const
{
	unit.m_armor.changeValue(m_armorReduce);
}

MagicPtr ArmorDebuffMagic::clone()const
{
	return MagicPtr(new ArmorDebuffMagic(m_name, m_manaCost,
		m_timer, m_armorReduce));
}

bool ArmorDebuffMagic::isBuff()const
{
	return false;
}

bool ArmorDebuffMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (!canCast<ArmorDebuffMagic*>(magic))
		return NO;
	ArmorDebuffMagic* temp = DYNAMIC(ArmorDebuffMagic*, magic);
	return m_armorReduce == temp->m_armorReduce;
}

bool ArmorDebuffMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void ArmorDebuffMagic::putOn(Unit& unit)const
{
	unit.m_armor.changeValue(-m_armorReduce);
}

void ArmorDebuffMagic::showFullInfo()const
{
	Magic::showData();
	showData();
}

void ArmorDebuffMagic::showData()const
{
	std::cout << "Armor reduce: " << m_armorReduce << std::endl;
}