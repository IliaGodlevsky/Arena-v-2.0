#include "OffsetDamageBuffMagic.h"

OffsetDamageBuffMagic::OffsetDamageBuffMagic(std::string name, int manaCost,
	Timer timer, ArmorReduceElem armorReduce,
	DamageAmplifyElem damageAmplify)
	: ParamChangeMagic(name, manaCost, timer),
	m_damageAmplify(damageAmplify),
	m_armorReduce(armorReduce)
{

}

void OffsetDamageBuffMagic::effectUnit(Unit& unit)
{
	ParamChangeMagic::effectUnit(unit);
	m_damageAmplify.effectUnit(unit);
	m_armorReduce.effectUnit(unit);
}

void OffsetDamageBuffMagic::uneffectUnit(Unit& unit)
{
	m_damageAmplify.uneffectUnit(unit);
	m_armorReduce.uneffectUnit(unit);
}

MagicPtr OffsetDamageBuffMagic::clone()const
{
	return MagicPtr(new OffsetDamageBuffMagic(m_name, m_manaCost, m_timer,
		m_armorReduce, m_damageAmplify));
}

bool OffsetDamageBuffMagic::isBuff()const
{
	return true;
}

bool OffsetDamageBuffMagic::isDispelable()const
{
	return true;
}

bool OffsetDamageBuffMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<OffsetDamageBuffMagic*>(magic))
		return false;
	OffsetDamageBuffMagic* temp = DYNAMIC(OffsetDamageBuffMagic*, magic);
	return ParamChangeMagic::isEqual(magic)
		&& m_armorReduce == temp->m_armorReduce
		&& m_damageAmplify == temp->m_damageAmplify;
}

void OffsetDamageBuffMagic::showFullInfo()const
{
	ParamChangeMagic::showFullInfo();
	std::cout << "Takes " << m_armorReduce << " armor and adds "
		<< m_damageAmplify << " damage for " << m_timer.getDuration() << " rounds\n";
}