#include "ArmorBuffMagic.h"

#include "../../Unit/Unit.h"


ArmorBuffMagic::ArmorBuffMagic(std::string name, int manaCost,
	Timer timer, ArmorAmplifyElem armorAmplify)
	: ParamChangeMagic(name, manaCost, timer), 
	m_armorAmplify(armorAmplify)
{

}

void ArmorBuffMagic::effectUnit(Unit& unit)
{
	ParamChangeMagic::effectUnit(unit);
	m_armorAmplify.effectUnit(unit);
}

void ArmorBuffMagic::uneffectUnit(Unit& unit)
{
	m_armorAmplify.uneffectUnit(unit);
}

MagicPtr ArmorBuffMagic::clone()const
{
	return MagicPtr(new ArmorBuffMagic(m_name, m_manaCost, m_timer, m_armorAmplify));
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
	if (!canCast<ArmorBuffMagic*>(magic))
		return false;
	ArmorBuffMagic* temp = DYNAMIC(ArmorBuffMagic*, magic);
	return ParamChangeMagic::isEqual(magic)
		&& m_armorAmplify == temp->m_armorAmplify;
}

void ArmorBuffMagic::showFullInfo()const
{
	ParamChangeMagic::showFullInfo();
	std::cout << "Adds " << m_armorAmplify 
		<< " armor for " << m_timer.getDuration() << " rounds\n";

}