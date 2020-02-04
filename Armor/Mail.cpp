#include "Mail.h"

#include "../Unit/Unit.h"

Mail::Mail(std::string name, int armor, Vitals health)
	: Armor(name, armor), m_health(health)
{

}

void Mail::putOn(Unit& unit)const
{
	Armor::putOn(unit);
	unit.m_health = unit.m_health + m_health;
}

void Mail::putOff(Unit& unit)const
{
	Armor::putOff(unit);
	unit.m_health = unit.m_health - m_health;
}

void Mail::showFullInfo()const
{
	Armor::showFullInfo();
	std::cout << "Health add: " << m_health << std::endl;
}

ArmPtr Mail::clone()const
{
	return ArmPtr(new Mail(m_name, m_armor, m_health));
}