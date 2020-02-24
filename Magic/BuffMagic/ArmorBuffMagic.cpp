#include "ArmorBuffMagic.h"

#include "../../Unit/Unit.h"


ArmorBuffMagic::ArmorBuffMagic(std::string name, int manaCost,
	Time time, int armorAmplify)
	: ParamChangeMagic(name, manaCost, time,
		{ ParamChangeElemPtr(new ArmorAmplifyElem(armorAmplify)) })
{

}

MagicPtr ArmorBuffMagic::clone()const
{
	return MagicPtr(new ArmorBuffMagic(m_name, m_manaCost, 
		m_time, m_elemHolder));
}

bool ArmorBuffMagic::isBuff()const
{
	return true;
}

bool ArmorBuffMagic::isDispelable()const
{
	return true;
}

bool ArmorBuffMagic::isEqual(const MagicPtr& magic)const
{
	return canCast<ArmorBuffMagic*>(magic) &&
		ParamChangeMagic::isEqual(magic);
}