#include "Wizard.h"

#include "../Level/Level.h"
#include "../Arena/Arena.h"
#include "../Level/WizardLevel.h"

Wizard::Wizard(std::string name, DecisionPtr decision,
	ItemFactoryPtr factory, Factory<Magic>* secondFactory) : Unit(name, decision, factory)
{
	enum {
		START_DAMAGE = 2, START_ARMOR = 1, START_HEALTH = 175,
		START_HP_REGEN = 1, START_MANA = 110, START_MP_REGEN = 5
	};
	m_damage = Battles(START_DAMAGE);
	m_armor = Battles(START_ARMOR);
	m_health = Vitals(START_HEALTH, START_HEALTH, START_HP_REGEN);
	m_mana = Vitals(START_MANA, START_MANA, START_MP_REGEN);
	m_level = std::unique_ptr<Level>(new WizardLevel(this));
	m_mail->putOn(*this);
	m_shield->putOn(*this);
	m_magicBook.takeMagic(secondFactory->createItem());
}

Wizard::Wizard(const Wizard& unit)
	: Unit(unit)
{
	m_level = std::unique_ptr<Level>(new WizardLevel(this));
	*m_level = *unit.m_level;
	m_level->setOwner(this);
}

void Wizard::payMana(int manaCost)
{
	const double MANA_COST_REDUCE = 0.25;
	manaCost = static_cast<int>(manaCost * (1 - MANA_COST_REDUCE));
	Unit::payMana(manaCost);
}

bool Wizard::castMagic(Unit& unit, MagicPtr& magic)
{
	const int DURATION_ENHANCE = static_cast<int>(std::floor(*m_level / 3.0));
	magic->setStartTime(Arena::getCurrentRound() - DURATION_ENHANCE);
	return Unit::castMagic(unit, magic);
}