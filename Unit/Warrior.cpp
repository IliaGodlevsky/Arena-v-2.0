#include "Warrior.h"

#include "../Level/WarriorLevel.h"
#include "../Level/Level.h"

Warrior::Warrior(std::string name, DecisionPtr decision,
	ItemFactoryPtr factory) : Unit(name, decision, factory)
{
	m_damage = Battles(8);
	m_armor = Battles(3);
	m_health = Vitals(250, 250, 4);
	m_mana = Vitals(50, 50, 1);
	m_mail->putOn(*this);
	m_shield->putOn(*this);
	m_level = std::unique_ptr<Level>(new WarriorLevel(this));
}

Warrior::Warrior(const Warrior& unit)
	: Unit(unit)
{
	m_level = std::unique_ptr<Level>(new WarriorLevel(this));
	*m_level = *unit.m_level;
}