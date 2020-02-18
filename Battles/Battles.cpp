#include "Battles.h"
#include "../Globals/Globals.h"

Battles::Battles(int value)
	: m_value(value), m_additionalValue(0)
{

}

void Battles::changeValue(int value)
{
	m_value += value;
}

void Battles::changeAdditaionalValue(int additionalValue)
{
	m_additionalValue += additionalValue;
}

void Battles::showShortInfo(const char* valueType)const
{
	std::cout << valueType << ": " << m_value;
	if (m_additionalValue != 0)
	{
		setBattlesColor();
		std::cout.setf(std::ios_base::showpos);
		std::cout << " " << m_additionalValue;
		setColor();
		std::cout.unsetf(std::ios_base::showpos);
	}
}

void Battles::setBattlesColor()const
{
	if (m_additionalValue > 0)
		setColor(LIGHT_GREEN);
	else if (m_additionalValue < 0)
		setColor(LIGHT_RED);
}

Battles::operator int()const
{
	return m_value + m_additionalValue;
}