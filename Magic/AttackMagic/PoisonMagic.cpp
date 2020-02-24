#include "../../Unit/Unit.h"

#include "PoisonMagic.h"

PoisonMagic::PoisonMagic(std::string name, int manaCost, Time time, int regenReduce)
	: ParamChangeMagic(name, manaCost, time,
		{ ParamChangeElemPtr(new HpRegenReduceElem(regenReduce)) })
{

}

bool PoisonMagic::isDispelable()const
{
	return false;
}

MagicPtr PoisonMagic::clone()const
{
	return MagicPtr(new PoisonMagic(m_name, m_manaCost, m_time, m_elemHolder));
}

bool PoisonMagic::isBuff()const
{
	return false;
}

bool PoisonMagic::isEqual(const MagicPtr& magic)const
{
	return canCast<PoisonMagic*>(magic) 
		&& ParamChangeMagic::isEqual(magic);
}