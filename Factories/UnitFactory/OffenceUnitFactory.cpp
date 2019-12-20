#include "OffenceUnitFactory.h"
#include "../ItemFactory/OffenceItemFactory.h"

OffenceUnitFactory::OffenceUnitFactory()
	: UnitFactory()
{
	m_factory = new OffenceItemFactory();
}

UnitPtr OffenceUnitFactory::createUnit()const
{
	return UnitFactory::createUnit();
}

OffenceUnitFactory::~OffenceUnitFactory()
{
	delete m_factory;
}