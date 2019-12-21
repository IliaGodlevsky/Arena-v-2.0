#include "UnitFactory.h"
#include "../../Decision/HumanDecision.h"

UnitFactory::UnitFactory()
	: m_decisions(0)
{
	m_decisions.push_back(DecisionPtr(new HumanDecision()));
	/*m_decisions[1] = DecisionPtr(new ComputerDecision());*/
	m_unitsNames.push_back("Amy");
	m_unitsNames.push_back("Sally");
	m_unitsNames.push_back("Cranny");
}

UnitPtr UnitFactory::createUnit()const
{
	std::string randomName = m_unitsNames[randomNumber(m_unitsNames.size() - 1)];
	index decisionIndex = inputNumber("Choose decision: ", m_decisions.size(), 1);
	return UnitPtr(new Unit(randomName, m_decisions[decisionIndex - 1], m_factory));
}

UnitFactory::~UnitFactory()
{
	
}