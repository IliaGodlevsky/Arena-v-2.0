#include "../../Unit/Unit.h"

#include "DamageDebuffMagic.h"

DamageDebuffMagic::DamageDebuffMagic(std::string name, int manaCost,
	Time time, DamageReduceElem damageReduce)
	: ParamChangeMagic(name, manaCost, time),
	m_damageReduce(damageReduce)
{

}

void DamageDebuffMagic::effectUnit(Unit& unit)
{
	ParamChangeMagic::effectUnit(unit);
	m_damageReduce.effectUnit(unit);
}

void DamageDebuffMagic::uneffectUnit(Unit& unit)
{
	m_damageReduce.uneffectUnit(unit);
}

MagicPtr DamageDebuffMagic::clone()const
{
	return MagicPtr(new DamageDebuffMagic(m_name, m_manaCost, m_time, m_damageReduce));
}

bool DamageDebuffMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<DamageDebuffMagic*>(magic))
		return false;
	DamageDebuffMagic* temp = DYNAMIC(DamageDebuffMagic*, magic);
	return ParamChangeMagic::isEqual(magic) &&
		m_damageReduce == temp->m_damageReduce;
}

bool DamageDebuffMagic::isBuff()const
{
	return false;
}

bool DamageDebuffMagic::isDispelable()const
{
	return true;
}

void DamageDebuffMagic::showFullInfo()const
{
	ParamChangeMagic::showFullInfo();
	std::cout << "Reduces enemy damage by "
		<< m_damageReduce << " for " << getDuration() << " rounds\n";
}