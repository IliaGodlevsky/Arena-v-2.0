#include "WizardFactory.h"

#include "../../Unit/Wizard.h"
#include "../../Factories/MagicFactories/AttackFactories/AttackAndStunMagicFactory.h"
#include "../../Factories/MagicFactories/AttackFactories/AttackMagicFactory.h"

WizardFactory::WizardFactory()
	: UnitFactory()
{
	m_secondMagics.push_back(new AttackAndStunMagicFactory());
	m_secondMagics.push_back(new AttackMagicFactory());
}

UnitPtr WizardFactory::createUnit()const
{
	index factoryNumber, decisionNumber, magicFactoryNumber;
	factoryNumber = inputNumber("1. Defence 2. Offence\n"
		"Choose item factory: ", m_itemFactories.size(), 1);
	decisionNumber = inputNumber("1. Human 2. RandomComputer\n3.SimpleComputer\n"
		"Choose decision: ", m_decisions.size(), 1);
	if (m_thread->joinable())
		m_thread->join();
	magicFactoryNumber = randomNumber(m_secondMagics.size() - 1);
	std::string randomName = m_unitsNames[randomNumber(m_unitsNames.size() - 1)];
	return UnitPtr(new Wizard(randomName, m_decisions[decisionNumber - 1],
		m_itemFactories[factoryNumber - 1], m_secondMagics[magicFactoryNumber]));
}

WizardFactory::~WizardFactory()
{
	for (size_t i = 0; i < m_secondMagics.size(); i++)
		delete m_secondMagics[i];
}