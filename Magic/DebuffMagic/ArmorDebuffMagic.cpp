#include "ArmorDebuffMagic.h"

#include "../../Unit/Unit.h"


ArmorDebuffMagic::ArmorDebuffMagic(std::string name, int manaCost,
	Timer timer, ArmorReduceElem armorReduce)
	: ParamChangeMagic(name, manaCost, timer),
	m_armorReduce(armorReduce)
{

}

void ArmorDebuffMagic::effectUnit(Unit& unit)
{
	ParamChangeMagic::effectUnit(unit);
	m_armorReduce.effectUnit(unit);
}

void ArmorDebuffMagic::uneffectUnit(Unit& unit)
{
	m_armorReduce.uneffectUnit(unit);
}

MagicPtr ArmorDebuffMagic::clone()const
{
	return MagicPtr(new ArmorDebuffMagic(m_name, m_manaCost, m_timer, m_armorReduce));
}

bool ArmorDebuffMagic::isBuff()const
{
	return false;
}

bool ArmorDebuffMagic::isDispelable()const
{
	return true;
}

bool ArmorDebuffMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<ArmorDebuffMagic*>(magic))
		return false;
	ArmorDebuffMagic* temp = DYNAMIC(ArmorDebuffMagic*, magic);
	return ParamChangeMagic::isEqual(magic)
		&& m_armorReduce == temp->m_armorReduce;
}

void ArmorDebuffMagic::showFullInfo()const
{

}