#include <cmath>

#include "Battles.h"

Battles::Battles(int value)
	: m_value(value)
{

}

void Battles::changeValue(int value)
{
	m_value += value;
}

Battles::operator int()const
{
	return m_value;
}