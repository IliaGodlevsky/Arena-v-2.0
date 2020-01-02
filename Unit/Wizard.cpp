#include "Wizard.h"

#include "../Level/Level.h"
#include "../Arena/Arena.h"
#include "../Level/WizardLevel.h"

Wizard::Wizard(DecisionPtr decision, ItemFactoryPtr factory, 
	Factory<Magic>* secondFactory) : Unit(decision, factory)
{
	enum {
		START_DAMAGE = 4, START_ARMOR = 2, START_HEALTH = 180,
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
	Unit::payMana(countManaCost(manaCost));
}

bool Wizard::castMagic(Unit& unit, MagicPtr& magic)
{
	const int DURATION_ENHANCE = static_cast<int>(std::floor(*m_level / 3.0));
	magic->setStartTime(Arena::getCurrentRound() - DURATION_ENHANCE);
	return Unit::castMagic(unit, magic);
}

int Wizard::countManaCost(int manaCost)const
{
	const double MANA_COST_REDUCE = 0.05;
	return static_cast<int>(manaCost * (1 - MANA_COST_REDUCE * (*m_level)));
}

bool Wizard::isEnoughManaFor(const MagicPtr& magic)const
{
	return m_mana >= countManaCost(magic->getCost());
}