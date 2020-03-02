#include "UnitFactory.h"
#include "../../Decision/HumanDecision.h"
#include "../../Decision/RandomComputerDecision.h"
#include "../../Decision/SimpleComputerDecision.h"

UnitFactory::UnitFactory():
	m_decisions(0)
{
	m_decisions.push_back(DecisionPtr(new HumanDecision()));
	m_decisions.push_back(DecisionPtr(new RandomComputerDecision()));
	m_decisions.push_back(DecisionPtr(new SimpleComputerDecision()));
}

index UnitFactory::chooseDecsion()const
{
	if (m_decisions.empty())
		throw BadEquipmentException("\nNo actual desicions for gamers. Bad class is "
			+ std::string(typeid(*this).name()));
	return inputNumber("\t\t\t1. Human 2. Easy AI 3. "
		"Normal AI\n\t\t\tChoose decision: ", (int)m_decisions.size(), 1);
}