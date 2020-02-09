#include "Warrior.h"

#include "../Level/WarriorLevel.h"
#include "../Level/Level.h"
#include "../PossibilityCounter/PosibilityCounter.h"

Warrior::Warrior(DecisionPtr decision, ItemFactoryPtr factory)
	: Unit(decision, factory)
{
	enum { 
		START_DAMAGE = 9, START_ARMOR = 2, START_HEALTH = 200, 
		START_HP_REGEN = 4, START_MANA = 65, START_MP_REGEN = 2
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
	if (m_stateHolder.canAttack() && nullptr != m_weapon)
	{
		const int multiDamage = damageMultiply(m_damage);
		m_weapon->injureUnit(unit, multiDamage);
		secondHit(unit);
		return true;
	}
	return false;
}

int Warrior::damageMultiply(int damage)const
{
	// Each level warrior deals more damage
	constexpr double DAMAGE_ENHANCE = 0.05;
	return static_cast<int>(std::ceil(damage  *
		(1 + DAMAGE_ENHANCE * (*m_level - 1))));
}

bool Warrior::secondHit(Unit& unit)
{
	// Each level warrior has more chance to hit enemy twice
	constexpr int secondHitPossibility = 7;
	if (PosibilityCounter(secondHitPossibility * (*m_level)))
	{
		signal(Signals::WAIT_TIME, Signals::DOUBLE_ATTACK);
		std::cout << getName() << " hitted "
			<< unit.getName() << " twice\n";
		const int multiDamage = damageMultiply(m_damage) / 2;
		m_weapon->injureUnit(unit, multiDamage);
		return true;
	}
	return false;
}