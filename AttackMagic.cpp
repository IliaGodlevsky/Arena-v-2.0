#include <iostream>

#include "AttackMagic.h"
#include "Unit.h"
#include "State.h"

Attack::Attack(std::string name, int manaCost, int damage)
	: Magic(name, manaCost, 0), m_damage(damage)
{

}

void Attack::effectUnit(Unit& unit)
{
	unit.m_health = unit.m_health - m_damage;
}

void Attack::uneffectUnit(Unit& unit)const
{
	return;
}

MagicPtr Attack::clone()const
{
	return MagicPtr(new Attack(m_name, m_manaCost, m_damage));
}

bool Attack::isBuff()const
{
	return false;
}

bool Attack::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	Attack* temp = DYNAMIC(Attack*, magic);
	if (nullptr == temp)
		return false;
	return m_damage == temp->m_damage;
}

bool Attack::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void Attack::putOn(Unit& unit)const
{
	return;
}

void Attack::showFullInfo()const
{
	Magic::showData();
	showData();
}

void Attack::showData()const
{
	std::cout << "Deals " << m_damage << std::endl;
}
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++ */
AttackAndStun::AttackAndStun(std::string name, int manaCost,
	int duration, int damage)
	: Magic(name, manaCost, duration), 
	Attack(name, manaCost, damage)
{

}

void AttackAndStun::effectUnit(Unit& unit)
{
	putOn(unit);
	unit.m_stateHolder.RecieveNewState(new StunState(m_durationmeter));
	Attack::effectUnit(unit);
}

void AttackAndStun::uneffectUnit(Unit& unit)const
{
	Attack::uneffectUnit(unit);
}

MagicPtr AttackAndStun::clone()const
{
	return MagicPtr(new AttackAndStun(m_name, m_manaCost, m_durationmeter, m_damage));
}

bool AttackAndStun::isBuff()const
{
	return false;
}

bool AttackAndStun::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	AttackAndStun* temp = DYNAMIC(AttackAndStun*, magic);
	if (nullptr == temp)
		return false;
	return Attack::hasEqualParametres(magic);
}

bool AttackAndStun::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void AttackAndStun::showFullInfo()const
{
	Magic::showData();
	showData();
}

void AttackAndStun::showData()const
{
	Attack::showData();
	std::cout << "Stuns unit for " << m_durationmeter << " rounds\n";
}

void AttackAndStun::putOn(Unit& unit)const
{
	Attack::putOn(unit);
}

/* ++++++++++++++++++++++++++++++++++++++++++++++++++++ */
Poison::Poison(std::string name, int manaCost, int duration,
	int regenReduce)
	: Magic(name, manaCost, duration), m_regenReduce(regenReduce)
{

}

void Poison::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void Poison::uneffectUnit(Unit& unit)const
{
	unit.m_health.ChangeRegeneration(m_regenReduce);
}

MagicPtr Poison::clone()const
{
	return MagicPtr(new Poison(m_name, m_manaCost, m_durationmeter, m_regenReduce));
}

bool Poison::isBuff()const
{
	return false;
}

bool Poison::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	Poison* temp = DYNAMIC(Poison*, magic);
	if (nullptr == temp)
		return false;
	return m_regenReduce == temp->m_regenReduce;
}

bool Poison::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void Poison::putOn(Unit& unit)const
{
	unit.m_health.ChangeRegeneration(-m_regenReduce);
}

void Poison::showFullInfo()const
{
	Magic::showData();
	showData();
}

void Poison::showData()const
{
	std::cout << "Deals " << m_regenReduce << " per round\n";
}
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++ */
PoisonAndAttack::PoisonAndAttack(std::string name, int manaCost,
	int duration, int damage, int regenReduce)
	: Magic(name, manaCost, duration),
	Poison(name, manaCost, duration, regenReduce),
	Attack(name, manaCost, damage)
{

}

void PoisonAndAttack::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void PoisonAndAttack::uneffectUnit(Unit& unit)const
{
	Poison::uneffectUnit(unit);
	Attack::uneffectUnit(unit);
}

MagicPtr PoisonAndAttack::clone()const
{
	return MagicPtr(new PoisonAndAttack(m_name, m_manaCost,
		m_durationmeter, m_damage, m_regenReduce));
}

bool PoisonAndAttack::isBuff()const
{
	return false;
}

bool PoisonAndAttack::hasEqualParametres(const MagicPtr& magic)const
{
	return Poison::hasEqualParametres(magic)
		&& Attack::hasEqualParametres(magic);
}

bool PoisonAndAttack::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void PoisonAndAttack::putOn(Unit& unit)const
{
	Attack::putOn(unit);
	Poison::putOn(unit);
}

void PoisonAndAttack::showFullInfo()const
{
	Magic::showData();
	showData();
}

void PoisonAndAttack::showData()const
{
	Attack::showData();
	Poison::showData();
}