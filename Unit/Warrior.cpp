#include "Warrior.h"

#include "../Level/WarriorLevel.h"
#include "../Level/Level.h"
#include "../PossibilityCounter/PosibilityCounter.h"
#include "../Factories/ItemFactory/WarriorItemFactory.h"
#include "../ParametresInitialiser/WarriorParamInitialiser.h"

Warrior::Warrior(DecisionPtr decision)
	: Unit(decision, 
		ItemFactoryPtr(new WarriorItemFactory()),
		LevelPtr(new WarriorLevel(this)), 
		ParamInitPtr(new WarriorParamInitialiser))
{

}

Warrior::Warrior(const Warrior& unit)
	: Unit(unit)
{

}

Warrior::Warrior(Warrior&& unit)
	: Warrior(unit)
{

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
	constexpr int SECOND_HIT_POSSIBILITY = 7;
	if (PosibilityCounter(SECOND_HIT_POSSIBILITY * (*m_level)))
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