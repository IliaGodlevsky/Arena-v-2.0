#include <cmath>

#include "../Arena/Arena.h"
#include "../Magic/Magic.h"

#include "Unit.h"


Unit::Unit(std::string name, DecisionPtr decision, ItemFactory* factory)
	: m_damage(4), 
	m_armor(2),
	m_magicBook(this), 
	m_name(name),
	m_level(this),
	m_magicOnMe(this), 
	m_decision(decision),
	m_stateHolder(decision)
{
	m_magicBook.takeMagic(factory->createMagic());
	m_weapon = factory->createWeapon();
	m_mail = factory->createArmor();
	m_shield = factory->createShield();
}

const std::string& Unit::getName()const
{
	return m_name;
}

void Unit::levelUp()
{
	m_level++;
}

bool Unit::isAlive()const
{
	return m_health > 0;
}

void Unit::recieveNewState(StatePtr Unitstate)
{
	this->m_stateHolder.recieveNewState(Unitstate);
}

void Unit::moveIntoNewRound()
{
	m_magicOnMe.takeOfExpiredMagic(Arena::getCurrentRound());
	m_stateHolder.takeOfExpiredStates(Arena::getCurrentRound());
	m_health++;
	m_mana++;
}

bool Unit::isEnoughManaFor(const MagicPtr& magic)const
{
	return m_mana >= magic->getCost();
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
	return false;
}

int Unit::calculateDamageAbsorb(int damage)const
{
	// The formula is taken from WarCraft 3
	const double REDUCE_CONST = 0.06;
	const double numerator = static_cast<double>(m_armor * REDUCE_CONST);
	double percent_of_reduce = numerator / (1.0 + numerator);
	return static_cast<int>(std::ceil(damage * (1.0 - percent_of_reduce)));
}

UnitPtr Unit::chooseUnitToAttack(const Gladiators& units)const
{
	return m_stateHolder.chooseUnitToAttack(*this, units);
}

MagicPtr Unit::chooseMagicToCast(const Gladiators& units)const
{
	return m_stateHolder.chooseMagicToCast(*this, units);
}

UnitPtr Unit::chooseUnitToCast(const MagicPtr& magicToCast, const Gladiators& units)const
{
	return m_stateHolder.chooseUnitToCast(*this, magicToCast, units);
}

void Unit::showFullInfo()const
{
	std::cout << getName() << " Level: " 
		<< m_level << std::endl;
	std::cout << "HP: " << m_health << " MP: " 
		<< m_mana << " DMG: " << m_damage
		<< " Arm: " << m_armor << std::endl;
	m_stateHolder.showShortInfo();
	m_magicBook.showShortInfo();
	m_magicOnMe.showShortInfo();
	std::cout << std::endl;
	std::cout << "Waepon: ";
	m_weapon->showShortInfo();
	std::cout << std::endl;
	std::cout << "Armor: ";
	m_mail->showShortInfo();
	std::cout << "Shield: ";
	m_shield->showShortInfo();
}

Unit::~Unit()
{
	
}