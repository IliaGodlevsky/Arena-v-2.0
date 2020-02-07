#include "ArmorAndDamageBuffMagic.h"

ArmorAndDamageBuffMagic::ArmorAndDamageBuffMagic(std::string name, int manaCost,
	Time time, ArmorAmplifyElem armorAmplify,
	DamageAmplifyElem damageAmplify)
	: ParamChangeMagic(name, manaCost, time),
	m_armorAmplify(armorAmplify),
	m_damageAmplify(damageAmplify)
{

}

void ArmorAndDamageBuffMagic::effectUnit(Unit& unit)
{
	ParamChangeMagic::effectUnit(unit);
	m_armorAmplify.effectUnit(unit);
	m_damageAmplify.effectUnit(unit);
}

void ArmorAndDamageBuffMagic::uneffectUnit(Unit& unit)
{
	m_armorAmplify.uneffectUnit(unit);
	m_damageAmplify.uneffectUnit(unit);
}

MagicPtr ArmorAndDamageBuffMagic::clone()const
{
	return MagicPtr(new ArmorAndDamageBuffMagic(m_name, m_manaCost, m_time,
		m_armorAmplify, m_damageAmplify));
}

bool ArmorAndDamageBuffMagic::isBuff()const
{
	return true;
}

bool ArmorAndDamageBuffMagic::isDispelable()const
{
	return true;
}

bool ArmorAndDamageBuffMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<ArmorAndDamageBuffMagic*>(magic))
		return false;
	ArmorAndDamageBuffMagic* temp = DYNAMIC(ArmorAndDamageBuffMagic*, magic);
	return ParamChangeMagic::isEqual(magic)
		&& m_armorAmplify == temp->m_armorAmplify
		&& m_damageAmplify == temp->m_damageAmplify;
}

void ArmorAndDamageBuffMagic::showFullInfo()const
{
	ParamChangeMagic::showFullInfo();
	std::cout << "Adds " << m_armorAmplify << " armor and "
		<< m_damageAmplify << " damage for " << getDuration() << " rounds\n";
}