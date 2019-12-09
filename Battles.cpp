#include "Battles.h"

Battles::Battles(int value)
	: m_value(value)
{

}

void Battles::changeValue(int value)
{
	this->m_value += value;
}

Battles::operator int()const
{
	return m_value;
}