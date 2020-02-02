#include "WizardFactory.h"

#include "../../Unit/Wizard.h"
#include "../../Factories/MagicFactories/AttackFactories/AttackAndStunMagicFactory.h"
#include "../../Factories/MagicFactories/AttackFactories/AttackMagicFactory.h"
#include "../ItemFactory/WizardItemFactory.h"

WizardFactory::WizardFactory()
	: UnitFactory()
{
	m_secondMagics.push_back(new AttackAndStunMagicFactory());
	m_secondMagics.push_back(new AttackMagicFactory());
	m_itemFactory = ItemFactoryPtr(new WizardItemFactory());
}

UnitPtr WizardFactory::createUnit()const
{
	index magicFactoryNumber = randomNumber((int)m_secondMagics.size() - 1);
	return UnitPtr(new Wizard(m_decisions[chooseDecsion() - 1]->clone(),
		m_itemFactory, m_secondMagics[magicFactoryNumber]));
}

UnitPtr WizardFactory::operator()()
{
	return createUnit();
}

WizardFactory::~WizardFactory()
{
	for (size_t i = 0; i < m_secondMagics.size(); i++)
		delete m_secondMagics[i];
}