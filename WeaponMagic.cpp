#include "WeaponMagic.h"
#include "Unit.h"
#include "State.h"

WeaponMagic::WeaponMagic(std::string name, int duration, int propability)
	: Magic(name, ZERO_MANA_COST, duration), m_propability(propability)
{

}

WeaponMagic::~WeaponMagic() {}

bool WeaponMagic::isCastChance()const
{
	return PosibilityCounter(m_propability);
}

void WeaponMagic::showFullInfo()const
{
	showData();
}

void WeaponMagic::showData()const
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Duration: " << m_durationmeter << std::endl;
	std::cout << "Posibility: " << m_propability << std::endl;
}

bool WeaponMagic::hasEqualParametres(const MagicPtr& magic)const
{
	WeaponMagic* temp = DYNAMIC(WeaponMagic*, magic);
	if (nullptr == temp)
		return false;
	return m_propability == temp->m_propability;
}

bool WeaponMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++ */
Degenerate::Degenerate(std::string name, int duration,
	int degeneration, int propability)
	: WeaponMagic(name, duration, propability),
	m_degeneration(degeneration)
{

}

void Degenerate::effectUnit(Unit& unit)
{
	if (isCastChance())
	{
		putOn(unit);
		Magic::effectUnit(unit);
	}
}

void Degenerate::uneffectUnit(Unit& unit)const
{
	unit.m_health.changeRegeneration(m_degeneration);
}

MagicPtr Degenerate::clone()const
{
	return MagicPtr(new Degenerate(m_name, m_durationmeter, m_degeneration, m_propability));
}

bool Degenerate::isBuff()const
{
	return false;
}

void Degenerate::putOn(Unit& unit)const
{
	unit.m_health.changeRegeneration(-m_degeneration);
}

bool Degenerate::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	Degenerate* temp = DYNAMIC(Degenerate*, magic);
	if (nullptr == temp)
		return false;
	return m_degeneration == temp->m_degeneration;
}

bool Degenerate::isEqual(const MagicPtr& magic)const
{
	return WeaponMagic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void Degenerate::showFullInfo()const
{
	WeaponMagic::showData();
	showData();
}

void Degenerate::showData()const
{
	std::cout << "Deals " << m_degeneration << " per round\n";
}
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++ */
Crush::Crush(std::string name, int damage,
	int propability)
	: WeaponMagic(name, ZERO_DURATION, propability), m_damage(damage)
{
	
}

void Crush::effectUnit(Unit& unit)
{
	if (isCastChance())
		putOn(unit);
}

void Crush::uneffectUnit(Unit& unit)const
{
	return;
}

MagicPtr Crush::clone()const
{
	return MagicPtr(new Crush(m_name, m_damage, m_propability));
}

bool Crush::isBuff()const
{
	return false;
}

void Crush::putOn(Unit& unit)const
{
	unit.m_health = unit.m_health - m_damage;
}

bool Crush::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	Crush* temp = DYNAMIC(Crush*, magic);
	if (nullptr == temp)
		return false;
	return m_damage == temp->m_damage;
}

bool Crush::isEqual(const MagicPtr& magic)const
{
	return WeaponMagic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void Crush::showFullInfo()const
{
	WeaponMagic::showData();
	showData();
}

void Crush::showData()const
{
	std::cout << "Damage: " << m_damage << std::endl;
}
////////////////////////////////////////////
Corruption::Corruption(std::string name, int duration,
	int armorReduce, int propability)
	: WeaponMagic(name, duration, propability),
	m_armorReduce(armorReduce)
{

}

void Corruption::effectUnit(Unit& unit)
{
	if (isCastChance())
	{
		putOn(unit);
		Magic::effectUnit(unit);
	}
}

void Corruption::uneffectUnit(Unit& unit)const
{
	unit.m_armor.changeValue(m_armorReduce);
}

MagicPtr Corruption::clone()const
{
	return MagicPtr(new Corruption(m_name, m_durationmeter, 
		m_armorReduce, m_propability));
}

bool Corruption::isBuff()const
{
	return false;
}

bool Corruption::isEqual(const MagicPtr& magic)const
{
	return WeaponMagic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void Corruption::showFullInfo()const
{
	WeaponMagic::showData();
	showData();
}

bool Corruption::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	Corruption* temp = DYNAMIC(Corruption*, magic);
	if (nullptr == temp)
		return false;
	return m_armorReduce == temp->m_armorReduce;
}

void Corruption::showData()const
{
	std::cout << "Armor reduce: " << m_armorReduce << std::endl;
}

void Corruption::putOn(Unit& unit)const
{
	unit.m_armor.changeValue(-m_armorReduce);
}

Stun::Stun(std::string name, int duration, int propability)
	: WeaponMagic(name, duration, propability)
{

}

void Stun::effectUnit(Unit& unit)
{
	if (isCastChance())
	{
		putOn(unit);
		Magic::effectUnit(unit);
	}
}

void Stun::uneffectUnit(Unit& unit)const
{
	return;
}

MagicPtr Stun::clone()const
{
	return MagicPtr(new Stun(m_name, 
		m_durationmeter, m_propability));
}

bool Stun::isBuff()const
{
	return false;
}

bool Stun::isEqual(const MagicPtr& magic)const
{
	return WeaponMagic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void Stun::showFullInfo()const
{
	WeaponMagic::showData();
	showData();
}

bool Stun::hasEqualParametres(const MagicPtr& magic)const
{
	return WeaponMagic::hasEqualParametres(magic);
}

void Stun::showData()const
{
	std::cout << "Stuns unit\n";
}

void Stun::putOn(Unit& unit)const
{
	unit.recieveNewState(StatePtr(new StunState(m_durationmeter)));
}