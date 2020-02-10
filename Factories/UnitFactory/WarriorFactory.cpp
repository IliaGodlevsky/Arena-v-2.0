#include "WarriorFactory.h"

#include "../ItemFactory/WarriorItemFactory.h"

WarriorFactory::WarriorFactory()
	: UnitFactory()
{

}

UnitPtr WarriorFactory::createUnit()const
{
	return UnitPtr(new Warrior(m_decisions[chooseDecsion() - 1]->clone()));
}

UnitPtr WarriorFactory::operator()()
{
	return createUnit();
}