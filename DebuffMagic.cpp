#include <iostream>

#include "DebuffMagic.h"
#include "Unit.h"

DamageDebuff::DamageDebuff(std::string name,
	int manaCost, int duration, int damageReduce)
	: Magic(name, manaCost, duration), 
	m_damageReduce(damageReduce)
{

}

void DamageDebuff::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void DamageDebuff::uneffectUnit(Unit& unit)const
{
	unit.m_damage.ChangeValue(m_damageReduce);
}

MagicPtr DamageDebuff::clone()const
{
	return MagicPtr(new DamageDebuff(m_name, m_manaCost, m_durationmeter, m_damageReduce));
}

bool DamageDebuff::isBuff()const
{
	return false;
}

bool DamageDebuff::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	DamageDebuff* temp = DYNAMIC(DamageDebuff*, magic);
	if (nullptr == temp)
		return false;
	return m_damageReduce == temp->m_damageReduce;
}

bool DamageDebuff::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void DamageDebuff::putOn(Unit& unit)const
{
	unit.m_damage.ChangeValue(-m_damageReduce);
}

void DamageDebuff::showFullInfo()const
{
	Magic::showData();
	showData();
}

void DamageDebuff::showData()const
{
	std::cout << "Damage reduce: " << m_damageReduce << std::endl;
}
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++ */
ArmorDebuff::ArmorDebuff(std::string name, int manaCost,
	int duration, int armorReduce)
	: Magic(name, manaCost, duration), 
	m_armorReduce(armorReduce)
{

}

void ArmorDebuff::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void ArmorDebuff::uneffectUnit(Unit& unit)const
{
	unit.m_armor.ChangeValue(m_armorReduce);
}

MagicPtr ArmorDebuff::clone()const
{
	return MagicPtr(new ArmorDebuff(m_name, m_manaCost,
		m_durationmeter, m_armorReduce));
}

bool ArmorDebuff::isBuff()const
{
	return false;
}

bool ArmorDebuff::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	ArmorDebuff* temp = DYNAMIC(ArmorDebuff*, magic);
	if (nullptr == temp)
		return false;
	return m_armorReduce == temp->m_armorReduce;
}

bool ArmorDebuff::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void ArmorDebuff::putOn(Unit& unit)const
{
	unit.m_armor.ChangeValue(-m_armorReduce);
}

void ArmorDebuff::showFullInfo()const
{
	Magic::showData();
	showData();
}

void ArmorDebuff::showData()const
{
	std::cout << "Armor reduce: " << m_armorReduce << std::endl;
}
/* ++++++++++++++++++++++++++++++++++++++++++++++++++++ */
ArmorAndDamageDebuff::ArmorAndDamageDebuff(std::string name,
	int manaCost, int duration, int armorReduce, int damageReduce)
	: Magic(name, manaCost, duration),
	ArmorDebuff(name, manaCost, duration, armorReduce),
	DamageDebuff(name, manaCost, duration, damageReduce)
{

}

void ArmorAndDamageDebuff::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
}

void ArmorAndDamageDebuff::uneffectUnit(Unit& unit)const
{
	DamageDebuff::uneffectUnit(unit);
	ArmorDebuff::uneffectUnit(unit);
}

MagicPtr ArmorAndDamageDebuff::clone()const
{
	return MagicPtr(new ArmorAndDamageDebuff(m_name, m_manaCost,
		m_durationmeter, m_armorReduce, m_damageReduce));
}
bool ArmorAndDamageDebuff::isBuff()const
{
	return false;
}

bool ArmorAndDamageDebuff::hasEqualParametres(const MagicPtr& magic)const
{
	return ArmorDebuff::hasEqualParametres(magic)
		&& DamageDebuff::hasEqualParametres(magic);
}

bool ArmorAndDamageDebuff::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}

void ArmorAndDamageDebuff::putOn(Unit& unit)const
{
	DamageDebuff::putOn(unit);
	ArmorDebuff::putOn(unit);
}

void ArmorAndDamageDebuff::showFullInfo()const
{
	Magic::showData();
	showData();
}

void ArmorAndDamageDebuff::showData()const
{
	ArmorDebuff::showData();
	DamageDebuff::showData();
}

Silence::Silence(std::string name, int mana_cost,
	int duration)
	: Magic(name, mana_cost, duration)
{

}

void Silence::Effect(Unit& unit)
{
	PutOn(unit);
	Magic::Effect(unit);
	unit.RecieveNewState(new MutedState(durationmeter));
}

void Silence::Uneffect(Unit& unit)const
{
	return;
}

MagicPtr Silence::Clone()const
{
	return MagicPtr(new Silence(name, mana_cost, durationmeter));
}

bool Silence::IsBuff()const
{
	return false;
}

bool Silence::Equal(const MagicPtr& magic)const
{
	if (typeid(*magic) == typeid(*this))
		return Magic::Equal(magic);
	return false;
}

void Silence::PutOn(Unit& unit)const
{
	return;
}

void Silence::ShowFullInfo()const
{
	Magic::Data();
	Data();
}

void Silence::Data()const
{
	std::cout << "Enemy can't cast spells\n";
}