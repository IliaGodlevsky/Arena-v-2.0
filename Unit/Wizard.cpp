#include "Wizard.h"

#include "../Level/Level.h"
#include "../Arena/Arena.h"
#include "../Level/WizardLevel.h"
#include "../Interface/Interface.h"
#include "../Expiring/Expiring.h"
#include "../Factories/ItemFactory/WizardItemFactory.h"
#include "../ParametresInitialiser/WizardParamInitialiser.h"

Wizard::Wizard(DecisionPtr decision,
	Factory<Magic>* secondFactory) :
	Unit(decision, 
		ItemFactoryPtr(new WizardItemFactory()),
		LevelPtr(new WizardLevel(this)), 
		ParamInitPtr(new WizardParamInitialiser()))
{
	m_magicBook.takeNew(secondFactory->createItem());
}

Wizard::Wizard(const Wizard& unit)
	: Unit(unit)
{

}

Wizard::Wizard(Wizard&& unit)
	: Wizard(unit)
{

}

void Wizard::payMana(int manaCost)
{
	Unit::payMana(countManaCost(manaCost));
}

void Wizard::prepareMagic(MagicPtr& magic)const
{
	// Each 3 levels wizard gets one round to magic duration
	constexpr int LEVELS_PER_DURATION = 3;
	Expiring* expiring = DYNAMIC(Expiring*, magic);
	const int DURATION_ENHANCE = static_cast<int>(std::floor(*m_level / LEVELS_PER_DURATION));
	if (nullptr != expiring)
		expiring->setStartTime(Arena::getCurrentRound() + DURATION_ENHANCE);
}

int Wizard::countManaCost(int manaCost)const
{
	// Each level (starting from 1st) wizard pays less mana for magic
	constexpr double MANA_COST_REDUCE = 0.05;
	return static_cast<int>(manaCost * (1 - MANA_COST_REDUCE * (*m_level)));
}

bool Wizard::isEnoughManaFor(const MagicPtr& magic)const
{
	IManaCost* manaCost = DYNAMIC(IManaCost*, magic);
	return m_mana >= countManaCost(manaCost->getCost());
}