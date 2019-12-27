#include <cmath>

#include "../Arena/Arena.h"
#include "../Magic/Magic.h"
#include "../UnitState/NotEnoughManaUnitState.h"

#include "Unit.h"

Unit::Unit(std::string name, 
	DecisionPtr decision, ItemFactoryPtr factory) :
	m_magicBook(this),
	m_name(name),
	m_magicOnMe(this),
	m_decision(decision),
	m_stateHolder(decision)
{
	m_mana = Vitals(150, 150, 10);
	m_magicBook.takeMagic(factory->createMagic());
	m_weapon = factory->createWeapon();
	m_mail = factory->createArmor();
	m_mail->putOn(*this);
	m_shield = factory->createShield();
	m_shield->putOn(*this);
}

Unit::Unit(const Unit& unit)
	: m_damage(unit.m_damage),
	m_armor(unit.m_armor),
	m_magicBook(this),
	m_name(unit.m_name),
	m_magicOnMe(this),
	m_decision(unit.m_decision),
	m_stateHolder(m_decision),
	m_health(unit.m_health),
	m_mana(unit.m_mana)
{
	for (size_t i = 0; i < unit.m_magicBook.size(); i++)
		m_magicBook.takeMagic(unit.m_magicBook[i]);
	for (size_t i = 0; i < unit.m_magicOnMe.size(); i++)
		m_magicOnMe.push_back(unit.m_magicOnMe[i]->clone());
	// copy stateHolder
	m_weapon = unit.m_weapon->clone();
	m_mail = unit.m_mail->clone();
	m_shield = unit.m_shield->clone();
	m_mail->putOn(*this);
}

const std::string& Unit::getName()const
{
	return m_name;
}

void Unit::levelUp()
{
	m_level->operator++();
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
	if (!m_magicBook.canCastAnySpell())
		m_stateHolder.recieveNewState(StatePtr(new NotEnoughManaUnitState(this)));
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
	auto& messager = Messager::getIncstance();
	if (!m_shield->isReflectChance())
	{
		m_health = m_health - calculateDamageAbsorb(damage);
		return true;
	}
	messager.writeMessage(calculateDamageAbsorb(damage), " was reflected\n");
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
	return m_stateHolder.chooseMagicToCast(*this, units);
}

UnitPtr Unit::chooseUnitToCast(const MagicPtr& magicToCast, 
	const Gladiators& units)const
{
	return m_stateHolder.chooseUnitToCast(*this, magicToCast, units);
}

void Unit::showFullInfo()const
{
	std::cout << getName() << " Level: " 
		<< *m_level << std::endl;
	std::cout << "HP: " << m_health << " MP: "
		<< m_mana << " DMG: " 
		<< m_damage + m_weapon->getDamage()
		<< " Arm: " << m_armor << std::endl;
	m_stateHolder.showShortInfo();
	m_magicBook.showShortInfo();
	m_magicOnMe.showShortInfo();
	std::cout << std::endl;
	std::cout << "Weapon: ";
	m_weapon->showShortInfo();
	std::cout << std::endl;
	std::cout << "Armor: ";
	m_mail->showShortInfo();
	std::cout << "Shield: ";
	m_shield->showShortInfo();
}

UnitPtr Unit::clone()const
{
	return UnitPtr(new Unit(*this));
}

Unit::~Unit()
{
	
}