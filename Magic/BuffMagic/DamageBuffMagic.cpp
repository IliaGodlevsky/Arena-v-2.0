#include "../../Unit/Unit.h"

#include "DamageBuffMagic.h"

DamageBuffMagic::DamageBuffMagic(std::string name, int manaCost,
	Timer timer, DamageAmplifyElem damageAmplify)
	: ParamChangeMagic(name, manaCost, timer), 
	m_damageAmplify(damageAmplify)
{

}

void DamageBuffMagic::effectUnit(Unit& unit)
{
	ParamChangeMagic::effectUnit(unit);
	m_damageAmplify.effectUnit(unit);
}

void DamageBuffMagic::uneffectUnit(Unit& unit)
{
	m_damageAmplify.uneffectUnit(unit);
}

MagicPtr DamageBuffMagic::clone()const
{
	return MagicPtr(new DamageBuffMagic(m_name, m_manaCost, m_timer, m_damageAmplify));
}

bool DamageBuffMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<DamageBuffMagic*>(magic))
		return false;
	DamageBuffMagic* temp = DYNAMIC(DamageBuffMagic*, magic);
	return ParamChangeMagic::isEqual(magic)&&
		m_damageAmplify == temp->m_damageAmplify;
}

bool DamageBuffMagic::isBuff()const
{
	return true;
}

bool DamageBuffMagic::isDispelable()const
{
	return true;
}

void DamageBuffMagic::showFullInfo()const
{
	ParamChangeMagic::showFullInfo();
}