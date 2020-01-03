#include "WarriorFactory.h"

#include "../ItemFactory/WarriorItemFactory.h"

WarriorFactory::WarriorFactory()
	: UnitFactory()
{
	m_itemFactory = ItemFactoryPtr(new WarriorItemFactory());
}

UnitPtr WarriorFactory::createUnit()const
{
	return UnitPtr(new Warrior(m_decisions[chooseDecsion() - 1]->clone(), m_itemFactory));
}

UnitPtr WarriorFactory::operator()()
{
	return createUnit();
}