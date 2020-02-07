#include "ArmorAndDamageDebuffMagic.h"

ArmorAndDamageDebuffMagic::ArmorAndDamageDebuffMagic(std::string name, int manaCost,
	Time time, ArmorReduceElem armorReduce, DamageReduceElem damageReduce)
	: ParamChangeMagic(name, manaCost, time),
	m_armorReduce(armorReduce),
	m_damageReduce(damageReduce)
{

}

void ArmorAndDamageDebuffMagic::effectUnit(Unit& unit)
{
	ParamChangeMagic::effectUnit(unit);
	m_armorReduce.effectUnit(unit);
	m_damageReduce.effectUnit(unit);
}

void ArmorAndDamageDebuffMagic::uneffectUnit(Unit& unit)
{
	m_armorReduce.uneffectUnit(unit);
	m_damageReduce.uneffectUnit(unit);
}

MagicPtr ArmorAndDamageDebuffMagic::clone()const
{
	return MagicPtr(new ArmorAndDamageDebuffMagic(m_name, m_manaCost, m_time,
		m_armorReduce, m_damageReduce));
}

bool ArmorAndDamageDebuffMagic::isBuff()const
{
	return false;
}

bool ArmorAndDamageDebuffMagic::isDispelable()const
{
	return true;
}

bool ArmorAndDamageDebuffMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<ArmorAndDamageDebuffMagic*>(magic))
		return false;
	ArmorAndDamageDebuffMagic* temp = DYNAMIC(ArmorAndDamageDebuffMagic*, magic);
	return ParamChangeMagic::isEqual(magic)
		&& m_armorReduce == temp->m_armorReduce
		&& m_damageReduce == temp->m_damageReduce;
}

void ArmorAndDamageDebuffMagic::showFullInfo()const
{
	ParamChangeMagic::showFullInfo();
	std::cout << "Reduces enemy armor by " << m_armorReduce << " and enemy damage by "
		<< m_damageReduce << " for " << getDuration() << " rounds\n";
}