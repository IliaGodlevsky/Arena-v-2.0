#include "UnitFactory.h"
#include "../../Decision/HumanDecision.h"
#include "../../Decision/RandomComputerDecision.h"
#include "../../Decision/SimpleComputerDecision.h"
#include "../ItemFactory/DefenceItemFactory.h"
#include "../ItemFactory/OffenceItemFactory.h"

UnitFactory::UnitFactory():
	m_decisions(0),
	m_itemFactories(0)
{
	m_thread = std::unique_ptr<std::thread>(new std::thread([&]()
	{ m_unitsNames = loadFromFile("Names.txt"); }));
	m_decisions.push_back(DecisionPtr(new HumanDecision()));
	m_decisions.push_back(DecisionPtr(new RandomComputerDecision()));
	m_decisions.push_back(DecisionPtr(new SimpleComputerDecision())); 
	m_itemFactories.push_back(ItemFactoryPtr(new DefenceItemFactory()));
	m_itemFactories.push_back(ItemFactoryPtr(new OffenceItemFactory()));
}

UnitPtr UnitFactory::createUnit()const
{
	index factoryNumber, decisionNumber;
	factoryNumber = inputNumber("1. Defence 2. Offence\n"
		"Choose item factory: ", m_itemFactories.size(), 1);
	decisionNumber = inputNumber("1. Human 2. RandomComputer\n3.SimpleComputer\n"
		"Choose decision: ", m_decisions.size(), 1);
	if (m_thread->joinable())
		m_thread->join();
	std::string randomName = m_unitsNames[randomNumber(m_unitsNames.size() - 1)];
	return UnitPtr(new Unit(randomName, m_decisions[decisionNumber - 1], 
		m_itemFactories[factoryNumber - 1]));
}

UnitFactory::~UnitFactory()
{

}