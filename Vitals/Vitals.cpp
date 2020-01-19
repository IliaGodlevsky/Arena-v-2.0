#include <cmath>
#include <iostream>

#include "Vitals.h"
#include "../Globals/Globals.h"

Vitals::Vitals(int value, int maxValue,
	int valueRegeneration)
	: m_value(value), m_maxValue(maxValue),
	m_valueRegeneration(valueRegeneration)
{
	fixOverflow();
}

Vitals Vitals::operator++(int i)
{
	Vitals temp = *this;
	m_value += m_valueRegeneration;
	fixOverflow();
	if (DEAD_LINE == m_value)
		m_value = 1;
	return temp;
}

Vitals Vitals::operator-(int value)const
{
	Vitals temp = *this;
	temp.m_value = static_cast<int>(fdim(temp.m_value, value));
	return temp;
}

Vitals Vitals::operator+(const Vitals& vit)const
{
	int val = m_value + vit.m_value;
	int max_val = m_maxValue + vit.m_maxValue;
	int regen = m_valueRegeneration + vit.m_valueRegeneration;
	Vitals temp(val, max_val, regen);
	temp.fixOverflow();
	return temp;
}

Vitals Vitals::operator-(const Vitals& vit)const
{
	int val = static_cast<int>(fdim(m_value, vit.m_value));
	int max_val = static_cast<int>(fdim(m_maxValue, vit.m_maxValue));
	int regen = m_valueRegeneration - vit.m_valueRegeneration;
	Vitals temp(val, max_val, regen);
	temp.fixOverflow();
	return temp;
}

void Vitals::changeRegeneration(int regeneration)
{
	m_valueRegeneration += regeneration;
}

void Vitals::restore(int percent)
{
	m_value += static_cast<int>(m_maxValue * 
		static_cast<double>(percent / 100.00));
	fixOverflow();
}

bool Vitals::isDead()const
{
	return m_value == DEAD_LINE;
}

void Vitals::fixOverflow()
{
	if (m_value > m_maxValue)
		m_value = m_maxValue;
	if (m_value < DEAD_LINE)
		m_value = DEAD_LINE;
}

Vitals::operator int()const
{
	return m_value;
}

bool Vitals::isHighHpLevel()const
{
	return m_value <= m_maxValue && m_value >
		m_maxValue * HIGH_HP_LEVEL;
}

bool Vitals::isNormalHpLevel()const
{
	return m_value <= m_maxValue * HIGH_HP_LEVEL && 
		m_value > m_maxValue * LOW_HP_LEVEL;
}

void Vitals::setValueColor()const
{
	if (isHighHpLevel())
		setColor(LIGHT_GREEN);
	else if (isNormalHpLevel())
		setColor(YELLOW);
	else
		setColor(LIGHT_RED);
}

void Vitals::setRegenColor()const
{
	if (m_valueRegeneration > 0)
		setColor(LIGHT_GREEN);
	else
		setColor(LIGHT_RED);
}

void Vitals::showFullInfo(const char* vitalsType)const
{
	std::cout << vitalsType << ": ";
	setValueColor();
	std::cout << m_value;
	setColor();
	std::cout << "\\" << m_maxValue << " " << vitalsType;
	std::cout << " regen: ";
	setRegenColor();
	std::cout << m_valueRegeneration << std::endl;
	setColor();
}