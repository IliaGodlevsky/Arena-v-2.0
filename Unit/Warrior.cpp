#include "Warrior.h"

#include "../Level/WarriorLevel.h"
#include "../Level/Level.h"

Warrior::Warrior(DecisionPtr decision, ItemFactoryPtr factory)
	: Unit(decision, factory)
{
	enum { 
		START_DAMAGE = 10, START_ARMOR = 3, START_HEALTH = 250, 
		START_HP_REGEN = 5, START_MANA = 60, START_MP_REGEN = 1
	};
	m_damage = Battles(START_DAMAGE);
	m_armor = Battles(START_ARMOR);
	m_health = Vitals(START_HEALTH, START_HEALTH, START_HP_REGEN);
	m_mana = Vitals(START_MANA, START_MANA, START_MP_REGEN);
	m_mail->putOn(*this);
	m_shield->putOn(*this);
	m_level = std::unique_ptr<Level>(new WarriorLevel(this));
}

Warrior::Warrior(const Warrior& unit)
	: Unit(unit)
{
	m_level = std::unique_ptr<Level>(new WarriorLevel(this));
	*m_level = *unit.m_level;
	m_level->setOwner(this);
}

bool Warrior::injureUnit(Unit& unit)
{
	if (nullptr == m_weapon)
		return false;
	const double DAMAGE_ENHANCE = 0.04;
	int newDamage = static_cast<int>(std::ceil((m_damage + m_weapon->getDamage()) *
		(1 + DAMAGE_ENHANCE * (*m_level - 1))));
	m_weapon->injureUnit(unit, newDamage);
	return true;
}

