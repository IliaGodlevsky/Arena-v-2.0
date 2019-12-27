#include "WarriorFactory.h"

WarriorFactory::WarriorFactory()
	: UnitFactory()
{

}

UnitPtr WarriorFactory::createUnit()const
{
	index factoryNumber, decisionNumber;
	factoryNumber = inputNumber("1. Defence 2. Offence\n"
		"Choose item factory: ", m_itemFactories.size(), 1);
	decisionNumber = inputNumber("1. Human 2. RandomComputer\n3.SimpleComputer\n"
		"Choose decision: ", m_decisions.size(), 1);
	if (m_thread->joinable())
		m_thread->join();
	std::string randomName = m_unitsNames[randomNumber(m_unitsNames.size() - 1)];
	return UnitPtr(new Warrior(randomName, m_decisions[decisionNumber - 1],
		m_itemFactories[factoryNumber - 1]));
}