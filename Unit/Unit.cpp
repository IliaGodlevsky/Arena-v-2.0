#include <cmath>

#include "../Arena/Arena.h"
#include "../Magic/Magic.h"
#include "../UnitState/NotEnoughManaUnitState.h"
#include "../Level/Level.h"
#include "../Decision/RandomComputerDecision.h"

#include "Unit.h"

Unit::Unit(DecisionPtr decision, ItemFactoryPtr factory) :
	m_magicBook(this),
	m_magicOnMe(this),
	m_decision(decision),
	m_stateHolder(decision)
{
	m_magicBook.takeNew(factory->createMagic());
	m_weapon = factory->createWeapon();
	m_mail = factory->createArmor();
	m_shield = factory->createShield();
	m_level = std::unique_ptr<Level>(new Level(this));
}

Unit::Unit(const Unit& unit)
	: m_damage(unit.m_damage),
	m_armor(unit.m_armor),
	m_magicBook(this, unit.m_magicBook),
	m_name(unit.m_name),
	m_magicOnMe(this, unit.m_magicOnMe),
	m_decision(unit.m_decision),
	m_stateHolder(unit.m_decision, unit.m_stateHolder),
	m_health(unit.m_health),
	m_mana(unit.m_mana),
	m_weapon(unit.m_weapon->clone()),
	m_mail(unit.m_mail->clone()),
	m_shield(unit.m_shield->clone())
{
	m_level = std::unique_ptr<Level>(new Level(this));
}

const std::string& Unit::getName()const
{
	return m_name;
}

void Unit::setName(std::string name)
{
	m_name = m_decision->setName(name);
}

void Unit::levelUp()
{
	m_level->operator++();
}

bool Unit::isAlive()const
{
	return m_health > 0;
}

void Unit::takeAlly(const UnitPtr& unit)
{
	m_decision->takeAlly(unit);
}

void Unit::recieveNewState(StatePtr Unitstate)
{
	this->m_stateHolder.takeNew(Unitstate);
}

void Unit::takeKilledUnitMagic(const Unit& victim)
{
	m_decision->takeMagic(*this, victim);
}

void Unit::moveIntoNewRound()
{
	m_health++;
	m_mana++;
	m_magicOnMe.takeOffExpired(Arena::getCurrentRound());
	m_stateHolder.takeOffExpired(Arena::getCurrentRound());
	if (!m_magicBook.canCastAnySpell())
		m_stateHolder.takeNew(StatePtr(new NotEnoughManaUnitState(this)));
}

bool Unit::isEnoughManaFor(const MagicPtr& magic)const
{
	return m_mana >= magic->getCost();
}

bool Unit::isAlly(const UnitPtr& unit)const
{
	return m_decision->isAlly(unit);
}

void Unit::payMana(int manaCost)
{
	m_mana = m_mana - manaCost;
}


bool Unit::injureUnit(Unit& unit)
{
	if (nullptr == m_weapon)
		return false;
	m_weapon->injureUnit(unit, m_damage);
	return true;
}

bool Unit::castMagic(Unit& unit, MagicPtr& magic)
{
	if (!isEnoughManaFor(magic))
		return false;
	magic->effectUnit(unit);
	payMana(magic->getCost());
	return true;
}

bool Unit::takeDamage(int damage)
{
	if (!m_shield->isReflectChance())
	{
		m_health = m_health - calculateDamageAbsorb(damage);
		return true;
	}
	std::cout << "But attack was reflected\n";
	return false;
}

int Unit::calculateDamageAbsorb(int damage)const
{
	// The formula is taken from WarCraft 3
	const double REDUCE_CONST = 0.06;
	const double numerator = static_cast<double>(m_armor * REDUCE_CONST);
	double percent_of_reduce = numerator / (1.0 + numerator);
	return static_cast<int>(std::floor(damage * (1.0 - percent_of_reduce)));
}

UnitPtr Unit::chooseUnitToAttack(const Gladiators& units)const
{
	return m_stateHolder.chooseUnitToAttack(*this, units);
}

MagicPtr Unit::chooseMagicToCast(const Gladiators& units)const
{
	if (m_magicBook.size() == 0)
		throw EmptyContainerException("\nTry to fill the container. Bad container is\n"
			+ std::string(typeid(m_magicBook).name()) + " in " + std::string(typeid(*this).name()));
	return m_stateHolder.chooseMagicToCast(*this, units);
}

UnitPtr Unit::chooseUnitToCast(const MagicPtr& magicToCast, 
	const Gladiators& units)const
{
	return m_stateHolder.chooseUnitToCast(*this, magicToCast, units);
}

void Unit::showFullInfo()const
{
	if (nullptr == m_shield || nullptr == m_mail
		|| nullptr == m_weapon || nullptr == m_decision)
		throw BadEquipmentException("Unit doesn't have enough equipment to fight. Bad class is "
			+ std::string(typeid(*this).name()));
	std::cout << getName() << " Level: " 
		<< *m_level << ", " << m_decision->
		getDecisionType() << std::endl;
	m_health.showFullInfo("HP");
	m_mana.showFullInfo("MP");
	std::cout << "DMG: "
		<< m_damage + m_weapon->getDamage();
	std::cout << " Arm: " << m_armor << std::endl;
	m_stateHolder.showShortInfo();
	m_magicBook.showShortInfo();
	m_magicOnMe.showShortInfo();
	std::cout << "Weapon: ";
	m_weapon->showShortInfo();
	std::cout << "Armor: ";
	m_mail->showShortInfo();
	std::cout << "Shield: ";
	m_shield->showShortInfo();
}

UnitPtr Unit::getPureClone()const
{
	UnitPtr clone = UnitPtr(new Unit(*this));
	clone->m_weapon = clone->m_weapon->getPureWeapon();
	clone->m_shield = clone->m_shield->getPureShield();
	if (!clone->m_magicBook.canCastAnySpell())
		clone->m_stateHolder.takeNew(StatePtr(new NotEnoughManaUnitState(clone.get())));
	return clone;
}
