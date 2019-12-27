#include "Wizard.h"

#include "../Level/Level.h"
#include "../Level/WizardLevel.h"

Wizard::Wizard(std::string name, DecisionPtr decision,
	ItemFactoryPtr factory) : Unit(name, decision, factory)
{
	m_damage = Battles(2);
	m_armor = Battles(1);
	m_health = Vitals(175, 175, 1);
	m_mana = Vitals(110, 110, 5);
	m_level = std::unique_ptr<Level>(new WizardLevel(this));
	MagicPtr magic = factory->createMagic();
	while (magic->isEqual(*m_magicBook.begin()))
		magic = factory->createMagic();
	m_magicBook.takeMagic(magic);
}

Wizard::Wizard(const Wizard& unit)
	: Unit(unit)
{
	m_level = std::unique_ptr<Level>(new WizardLevel(this));
	*m_level = *unit.m_level;
}

void Wizard::payMana(int manaCost)
{
	manaCost = static_cast<int>(manaCost * 0.75);
	Unit::payMana(manaCost);
}