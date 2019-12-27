#include "../Unit/Unit.h"


#include "Level.h"

Level::Level(Unit* unit)
	: m_unit(unit)
{

}

Level::operator int()const
{
	return m_level;
}

void Level::setOwner(Unit* unit)
{
	m_unit = unit;
}