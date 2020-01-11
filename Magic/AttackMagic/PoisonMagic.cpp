#include "../../Unit/Unit.h"

#include "PoisonMagic.h"


PoisonMagic::PoisonMagic(std::string name, int manaCost, Timer timer,
	HpRegenReduceElem regenReduce)
	: ParamChangeMagic(name, manaCost, timer), m_regenReduce(regenReduce)
{

}

bool PoisonMagic::isDispelable()const
{
	return false;
}

void PoisonMagic::effectUnit(Unit& unit)
{
	ParamChangeMagic::effectUnit(unit);
	m_regenReduce.effectUnit(unit);
}

void PoisonMagic::uneffectUnit(Unit& unit)
{
	m_regenReduce.uneffectUnit(unit);
}

MagicPtr PoisonMagic::clone()const
{
	return MagicPtr(new PoisonMagic(m_name, m_manaCost, m_timer, m_regenReduce));
}

bool PoisonMagic::isBuff()const
{
	return false;
}

bool PoisonMagic::isEqual(const MagicPtr& magic)const
{
	if (!canCast<PoisonMagic*>(magic))
		return false;
	PoisonMagic* temp = DYNAMIC(PoisonMagic*, magic);
	return ParamChangeMagic::isEqual(magic)
		&& temp->m_regenReduce == m_regenReduce;
}

void PoisonMagic::showFullInfo()const
{
	Magic::showFullInfo();
	std::cout << "Reduces regen by " << m_regenReduce 
		<< " for " << m_timer.getDuration();
}