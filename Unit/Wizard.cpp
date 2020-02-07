#include "Wizard.h"

#include "../Level/Level.h"
#include "../Arena/Arena.h"
#include "../Level/WizardLevel.h"
#include "../Interface/Interface.h"
#include "../Expiring/Expiring.h"

Wizard::Wizard(DecisionPtr decision, ItemFactoryPtr factory, 
	Factory<Magic>* secondFactory) : Unit(decision, factory)
{
	enum {
		START_DAMAGE = 3, START_ARMOR = 1, START_HEALTH = 150,
		START_HP_REGEN = 2, START_MANA = 100, START_MP_REGEN = 5
	};
	m_damage = Battles(START_DAMAGE);
	m_armor = Battles(START_ARMOR);
	m_health = Vitals(START_HEALTH, START_HEALTH, START_HP_REGEN);
	m_mana = Vitals(START_MANA, START_MANA, START_MP_REGEN);
	m_level = std::unique_ptr<Level>(new WizardLevel(this));
	m_mail->putOn(*this);
	m_shield->putOn(*this);
	m_magicBook.takeNew(secondFactory->createItem());
	m_damage.changeValue(m_weapon->getDamage());
}

Wizard::Wizard(const Wizard& unit)
	: Unit(unit)
{
	m_level = std::unique_ptr<Level>(new WizardLevel(this));
	*m_level = *unit.m_level;
	m_level->setOwner(this);
}

Wizard::Wizard(Wizard&& unit)
	: Unit(unit)
{
	m_level = std::unique_ptr<Level>(new WizardLevel(this));
	*m_level = *unit.m_level;
	m_level->setOwner(this);
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