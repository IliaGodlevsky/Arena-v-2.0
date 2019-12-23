#include "UnitFactory.h"
#include "../../Decision/HumanDecision.h"
#include "../ItemFactory/DefenceItemFactory.h"
#include "../ItemFactory/OffenceItemFactory.h"

UnitFactory::UnitFactory():
	m_decisions(0),
	m_unitsNames(0),
	m_itemFactories(0)
{
	m_unitsNames.push_back("Amy");
	m_unitsNames.push_back("Sally");
	m_unitsNames.push_back("Cranny");
	m_decisions.push_back(DecisionPtr(new HumanDecision()));
	m_itemFactories.push_back(ItemFactoryPtr(new DefenceItemFactory()));
	m_itemFactories.push_back(ItemFactoryPtr(new OffenceItemFactory()));
}

UnitPtr UnitFactory::createUnit()const
{
	index factoryNumber, decisionNumber;
	factoryNumber = inputNumber("1. Defence 2. Offence\nChoose item factory: ",
		m_itemFactories.size(), 1);
	decisionNumber = inputNumber("1. Human 2. Computer\n Choose decision: ", 
		m_decisions.size(), 1);
	std::string randomName = m_unitsNames[randomNumber(m_unitsNames.size() - 1)];
	return UnitPtr(new Unit(randomName, m_decisions[decisionNumber - 1], 
		m_itemFactories[factoryNumber - 1]));
}