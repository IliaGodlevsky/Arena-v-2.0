#include "ArmorDebuffMagic.h"

#include "../../Unit/Unit.h"


ArmorDebuffMagic::ArmorDebuffMagic(std::string name, int manaCost,
	Time time, int armorReduce)
	: UnitParametresChangeMagic(name, manaCost, time, 
		{ParamChangeElemPtr(new ArmorReduceElem(armorReduce))})

{

}

MagicPtr ArmorDebuffMagic::clone()const
{
	return MagicPtr(new ArmorDebuffMagic(m_name, 
		m_manaCost, m_time, m_elemHolder));
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
	return canCast<ArmorDebuffMagic*>(magic) &&
		UnitParametresChangeMagic::isEqual(magic);
}