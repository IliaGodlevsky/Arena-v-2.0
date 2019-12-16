#include "Weapon.h"
#include "Unit.h"
#include "BadWeaponMagicException.h"

Weapon::Weapon(std::string name, int damage, int criticalStrikePropability)
	: m_name(name),m_damage(damage),m_CriticalStrikePropability(criticalStrikePropability)
{

}

Weapon::Weapon(const Weapon& weapon)
	: m_damage(weapon.m_damage)
{

}

Weapon& Weapon::operator=(const Weapon& weapon)
{
	if (this == &weapon)
		return *this;
	m_damage = weapon.m_damage;
	return *this;
}

bool Weapon::canSmashUnit(const Unit& unit)const
{
	return unit.m_health <= unit.calculateDamageAbsorb(m_damage);
}

void Weapon::showFullInfo()const
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Damage: " << m_damage << std::endl;
}

void Weapon::showShortInfo()const
{
	std::cout << "<" << m_name << ": " << m_damage << ">";
}

void Weapon::injureUnit(Unit& unit, int damage)const
{
	unit.takeDamage(multiplyDamage(m_damage + damage));
}

WeaponPtr Weapon::clone()const
{
	return WeaponPtr(new Weapon(m_name, m_damage,m_CriticalStrikePropability));
}

int Weapon::multiplyDamage(int damage)const
{
	const double DAMAGE_MULTIPLY = 1.5;
	if (PosibilityCounter(m_CriticalStrikePropability))
		return static_cast<int>(std::round(damage * DAMAGE_MULTIPLY));
	else
		return damage;
}
/////////////////////////////////////////////////////
MagicWeapon::MagicWeapon(std::string name, int damage, MagicPtr magic)
	: Weapon(name, damage, ZERO_CRITIAL_PROBABILITY), m_magic(magic->clone())
{
	
}

MagicWeapon::MagicWeapon(const MagicWeapon& weapon)
	: Weapon(weapon), m_magic(weapon.m_magic->clone())
{

}

MagicWeapon& MagicWeapon::operator=(const MagicWeapon& weapon)
{
	if (this == &weapon)
		return *this;
	Weapon::operator=(weapon);
	m_magic = weapon.m_magic->clone();
	return *this;
}

void MagicWeapon::injureUnit(Unit& unit, int dmg)const
{
	if (unit.takeDamage(multiplyDamage(m_damage + dmg)))
		m_magic->effectUnit(unit);
}

void MagicWeapon::showFullInfo()const
{
	Weapon::showFullInfo();
	m_magic->showFullInfo();
}
////////////////////////////////////////////////////
MagicSword::MagicSword(std::string name, int damage, MagicPtr magic)
	: MagicWeapon(name, damage, magic->clone())
{
	Degenerate* temp = DYNAMIC(Degenerate*, magic);
	if (nullptr == temp)
		throw BadWeaponMagicException("BadWeaponMagicException", magic);
}

MagicSword::MagicSword(const MagicSword& sword)
	: MagicWeapon(sword)
{

}

MagicSword& MagicSword::operator=(const MagicSword& sword)
{
	if (this == &sword)
		return *this;
	MagicWeapon::operator=(sword);
	return *this;
}

WeaponPtr MagicSword::clone()const
{
	return WeaponPtr(new MagicSword(m_name, m_damage, m_magic->clone()));
}
////////////////////////////////////////////////////////
MagicAxe::MagicAxe(std::string name, int damage, MagicPtr magic)
	:MagicWeapon(name, damage, magic->clone())
{
	Crush* temp = DYNAMIC(Crush*, magic);
	if (nullptr == temp)
		throw BadWeaponMagicException("BadWeaponMagicException", magic);
}

MagicAxe::MagicAxe(const MagicAxe& axe)
	: MagicWeapon(axe)
{

}

MagicAxe& MagicAxe::operator=(const MagicAxe& axe)
{
	if (this == &axe)
		return *this;
	MagicWeapon::operator=(axe);
	return *this;
}

WeaponPtr MagicAxe::clone()const
{
	return WeaponPtr(new MagicAxe(m_name, m_damage, m_magic->clone()));
}
//////////////////////////////////////////////////
MagicSpear::MagicSpear(std::string name, int damage, MagicPtr magic)
	: MagicWeapon(name, damage, magic->clone())
{
	Corruption* temp = DYNAMIC(Corruption*, magic);
	if (nullptr == temp)
		throw BadWeaponMagicException("BadWeaponMagicException", magic);
}

MagicSpear::MagicSpear(const MagicSpear& spear)
	: MagicWeapon(spear)
{

}

MagicSpear& MagicSpear::operator=(const MagicSpear& spear)
{
	if (this == &spear)
		return *this;
	MagicWeapon::operator=(spear);
	return *this;
}

WeaponPtr MagicSpear::clone()const
{
	return WeaponPtr(new MagicSpear(m_name, m_damage, m_magic->clone()));
}
////////////////////////////////////////////////////
MagicClub::MagicClub(std::string name, int damage, MagicPtr magic)
	: MagicWeapon(name, damage, magic->clone())
{
	Stun* temp = DYNAMIC(Stun*, magic);
	if (nullptr == temp)
		throw BadWeaponMagicException("BadWeaponMagicException", magic);
}

MagicClub::MagicClub(const MagicClub& club)
	: MagicWeapon(club)
{

}

MagicClub& MagicClub::operator=(const MagicClub& club)
{
	if (this == &club)
		return *this;
	MagicWeapon::operator=(club);
	return *this;
}

WeaponPtr MagicClub::clone()const
{
	return WeaponPtr(new MagicClub(m_name, m_damage, m_magic->clone()));
}