#include <cmath>

#include "../Arena/Arena.h"
#include "../Magic/Magic.h"
#include "../UnitState/InnerUnitState/NotEnoughManaUnitState.h"
#include "../UnitState/InnerUnitState/NotEnoughDamageState.h"
#include "../Level/Level.h"
#include "../Expiring/Expiring.h"
#include "../UnitState/InnerUnitState/DeadUnitState.h"
#include "../Magic/Elements/HpReduceElem.h"
#include "../UnitState/OuterUnitState/MutedUnitState.h"
#include "../UnitState/OuterUnitState/StunUnitState.h"
#include "Unit.h"

void setStartTime(const MagicPtr& magic, int round)
{
	const auto expiring = dCast<Expiring*>(magic);
	if (nullptr != expiring)
		expiring->setStartTime(round);
}

Unit::Unit(DecisionPtr decision)
	: Unit(decision, nullptr, nullptr, nullptr)

{

}

Unit::Unit(DecisionPtr decision, ItemFactoryPtr factory,
	LevelPtr level, ParamInitPtr initialiser) :
	m_magicBook(this),
	m_magicOnMe(this),
	m_decision(decision->clone()),
	m_stateHolder(this),
	m_level(std::move(level))
{
	m_damage = Battles(initialiser->getStartDamage());
	m_armor = Battles(initialiser->getStartArmor());
	m_health = Vitals( initialiser->getStartHp(), 
		initialiser->getStartHp(), initialiser->getStartHpRegen());
	m_mana = Vitals( initialiser->getStartMp(), 
		initialiser->getStartMp(), initialiser->getStartMpRegen());
	m_magicBook.takeNew(factory->createMagic());
	m_weapon = factory->createWeapon();
	m_mail = factory->createArmor();
	m_shield = factory->createShield();
	m_damage.changeValue(m_weapon->getDamage());
	m_mail->putOn(*this);
	m_shield->putOn(*this);
	if (m_magicBook.isEmpty())
		throw EmptyContainerException("MagicBook is empty");
	if (!hasEnoughEquipment())
		throw BadEquipmentException("Unit doesn't have enough equipment to fight");
}

Unit::Unit(const Unit& unit)
	: m_damage(unit.m_damage),
	m_armor(unit.m_armor),
	m_magicBook(this, unit.m_magicBook),
	m_name(unit.m_name),
	m_magicOnMe(this, unit.m_magicOnMe),
	m_decision(unit.m_decision->clone()),
	m_stateHolder(this, unit.m_stateHolder),
	m_health(unit.m_health),
	m_mana(unit.m_mana),
	m_weapon(unit.m_weapon->clone()),
	m_mail(unit.m_mail->clone()),
	m_shield(unit.m_shield->clone()),
	m_level(unit.m_level->clone())
{
	m_level->setOwner(this);
}

Unit::Unit(Unit&& unit)
	: Unit(unit)
{

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
	++*m_level;
	m_stateHolder.takeOffExpired();
}

bool Unit::isDead()const
{
	return m_health.isOutOf();
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
	if (!isDead())
	{
		m_health++;
		m_mana++;
		m_magicOnMe.takeOffExpired();
		m_stateHolder.takeOffExpired();
	}
}

bool Unit::isEnoughManaFor(const MagicPtr& magic)const
{
	const auto manaCost = dCast<IManaCost*>(magic);
	return m_mana >= manaCost->getCost();
}

bool Unit::isAlly(const Unit& unit)const
{
	return unit.m_teamNumber == m_teamNumber;
}

void Unit::payMana(int manaCost)
{
	m_mana = m_mana - manaCost;
}

bool Unit::injureUnit(Unit& unit)
{
	bool hasAttacked = false;
	if (m_stateHolder.canAttack() && nullptr != m_weapon)
	{
		m_weapon->injureUnit(unit, m_damage);
		hasAttacked = true;
	}
	return hasAttacked;
}

bool Unit::castMagic(Unit& unit, MagicPtr& magic)
{
	bool hasCasted = false;
	if (nullptr != magic)
	{	
		if (isEnoughManaFor(magic))
		{
			const auto manaCost = dCast<IManaCost*>(magic);
			prepareMagic(magic);
			unit.takeMagicEffect(*this, magic);
			payMana(manaCost->getCost());
			if (!m_magicBook.canCastAnySpell())
				m_stateHolder.takeNew(StatePtr(new 
					NotEnoughManaUnitState(this)));
			hasCasted = true;
		}
	}
	return hasCasted;
}

bool Unit::takeDamage(int damage)
{
	bool isDamaged = false;
	if (m_stateHolder.canTakeDamage(*this, damage))
	{
		HpReduceElem(calculateDamageAbsorb(m_armor, damage)).effectUnit(*this);		
		isDamaged = true;
	}
	if (isDead())
		m_stateHolder.takeNew(StatePtr(new DeadUnitState(this)));
	return isDamaged;
}

bool Unit::takeMagicEffect(Unit& caster, MagicPtr& magic)
{
	bool isEffected = false;
	if (m_stateHolder.canTakeMagicEffect(*this, caster, magic))
	{
		isEffected = true;
		magic->effectUnit(*this);
	}
	if (isDead())
		m_stateHolder.takeNew(StatePtr(new DeadUnitState(this)));
	if (m_damage <= 0)
		m_stateHolder.takeNew(StatePtr(new NotEnoughDamageState(this)));
	m_stateHolder.takeOffExpired();
	return isEffected;
}

void Unit::setTeam(int teamNumber)
{
	m_teamNumber = teamNumber;
}

UnitPtr Unit::chooseUnitToAttack(const Gladiators& units)const
{	
	if (m_stateHolder.canAttack())
		return m_decision->chooseUnitToAttack(*this, units);
	return nullptr;
}

MagicPtr Unit::chooseMagicToCast(const Gladiators& units)const
{
	if (m_stateHolder.canCast())
		return m_decision->chooseMagicToCast(*this, units);
	return nullptr;
}

UnitPtr Unit::chooseUnitToCast(const MagicPtr& magicToCast, 
	const Gladiators& units)const
{
	if (m_stateHolder.canCast())
		return m_decision->chooseUnitToCast(*this, magicToCast, units);
	return nullptr;
}

void Unit::showFullInfo()const
{
	setColor(TextColor(m_teamNumber + 7));
	std::cout << getName() << ", Level: " <<
		*m_level << ", " << "Team: "
		<< m_teamNumber << ", "
		<< m_decision->getDecisionType()
		<< std::endl;
	setColor();
	m_health.showFullInfo("HP");
	m_mana.showFullInfo("MP");
	m_damage.showShortInfo("DMG");
	std::cout << " ";
	m_armor.showShortInfo("ARM");
	std::cout << std::endl;
	std::cout << "States: ";
	m_stateHolder.showShortInfo();
	std::cout << "Magic: ";
	m_magicBook.showShortInfo();
	std::cout << "Effects: ";
	m_magicOnMe.showShortInfo();
	std::cout << "Weapon: ";
	m_weapon->showShortInfo();
	std::cout << "Armor: ";
	m_mail->showShortInfo();
	std::cout << "Shield: ";
	m_shield->showShortInfo();
	std::cout << std::endl;
}

UnitPtr Unit::getPureClone()const
{
	auto clone = UnitPtr(new Unit(*this));
	clone->m_weapon = clone->m_weapon->getPureWeapon();
	clone->m_shield = clone->m_shield->getPureShield();
	return clone;
}

void Unit::prepareMagic(MagicPtr& magic)const
{
	setStartTime(magic, Arena::getCurrentRound());
}

bool Unit::hasEnoughEquipment()const
{
	return nullptr != m_shield && nullptr != m_mail
		&& nullptr != m_weapon && nullptr != m_decision;
}
