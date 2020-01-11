#include "ArmorAndDamageDebuffMagic.h"

ArmorAndDamageDebuffMagic::ArmorAndDamageDebuffMagic(std::string name, int manaCost,
	Timer timer, ArmorReduceElem armorReduce, DamageReduceElem damageReduce)
	: ParamChangeMagic(name, manaCost, timer),
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
	return MagicPtr(new ArmorAndDamageDebuffMagic(m_name, m_manaCost, m_timer,
		m_armorReduce, m_damageReduce));
}

bool ArmorAndDamageDebuffMagic::isBuff()const
{
	return true;
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
}