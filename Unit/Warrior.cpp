#include "Warrior.h"

#include "../Level/WarriorLevel.h"
#include "../Level/Level.h"
#include "../PossibilityCounter/PosibilityCounter.h"

Warrior::Warrior(DecisionPtr decision, ItemFactoryPtr factory)
	: Unit(decision, factory)
{
	enum { 
		START_DAMAGE = 11, START_ARMOR = 3, START_HEALTH = 250, 
		START_HP_REGEN = 5, START_MANA = 60, START_MP_REGEN = 2
	};
	m_damage = Battles(START_DAMAGE);
	m_armor = Battles(START_ARMOR);
	m_health = Vitals(START_HEALTH, START_HEALTH, START_HP_REGEN);
	m_mana = Vitals(START_MANA, START_MANA, START_MP_REGEN);
	m_mail->putOn(*this);
	m_shield->putOn(*this);
	m_level = std::unique_ptr<Level>(new WarriorLevel(this));
	m_damage.changeValue(m_weapon->getDamage());
}

Warrior::Warrior(const Warrior& unit)
	: Unit(unit)
{
	m_level = std::unique_ptr<Level>(new WarriorLevel(this));
	*m_level = *unit.m_level;
	m_level->setOwner(this);
}

Warrior::Warrior(Warrior&& unit)
	: Unit(unit)
{
	m_level = std::unique_ptr<Level>(new WarriorLevel(this));
	*m_level = *unit.m_level;
	m_level->setOwner(this);
}

bool Warrior::injureUnit(Unit& unit)
{
	const int multiDamage = damageMultiply(m_damage);
	m_stateHolder.injureUnit(m_weapon, unit, multiDamage);
	secondHit(unit);
	return true;
}

int Warrior::damageMultiply(int damage)const
{
	const double DAMAGE_ENHANCE = 0.05;
	return static_cast<int>(std::ceil(damage  *
		(1 + DAMAGE_ENHANCE * (*m_level - 1))));
}

bool Warrior::secondHit(Unit& unit)
{
	const int secondHitPossibility = 7;
	if (PosibilityCounter(secondHitPossibility * (*m_level)))
	{
		signal(Signals::WAIT_TIME - 60, Signals::ATTACK_BLOCK);
		std::cout << getName() << " hitted "
			<< unit.getName() << " twice\n";
		const int multiDamage = damageMultiply(m_damage) / 2;
		return m_stateHolder.injureUnit(m_weapon, unit, multiDamage);
	}
	return false;
}