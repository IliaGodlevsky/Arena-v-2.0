#include "DefenceUnitFactory.h"
#include "../ItemFactory/DefenceItemFactory.h"

DefenceUnitFactory::DefenceUnitFactory()
	: UnitFactory()
{
	m_factory = new DefenceItemFactory();
}

UnitPtr DefenceUnitFactory::createUnit()const
{
	return UnitFactory::createUnit();
}

DefenceUnitFactory::~DefenceUnitFactory()
{
	delete m_factory;
}