#include "WarriorFactory.h"

#include "../ItemFactory/WarriorItemFactory.h"

WarriorFactory::WarriorFactory()
	: UnitFactory()
{
	m_itemFactory = ItemFactoryPtr(new WarriorItemFactory());
}

UnitPtr WarriorFactory::createUnit()const
{
	checkThread();
	std::string randomName = m_unitsNames[randomNumber(m_unitsNames.size() - 1)];
	return UnitPtr(new Warrior(randomName, m_decisions[chooseDecsion() - 1], m_itemFactory));
}