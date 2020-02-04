#include "WizardCloak.h"
#include "../Unit/Unit.h"

WizardCloak::WizardCloak(std::string name, int armor, Vitals mana)
	: Armor(name, armor), m_mana(mana)
{

}

void WizardCloak::putOn(Unit& unit)const
{
	Armor::putOn(unit);
	unit.m_mana = unit.m_mana + m_mana;
}

void WizardCloak::putOff(Unit& unit)const
{
	Armor::putOff(unit);
	unit.m_mana = unit.m_mana - m_mana;
}

void WizardCloak::showFullInfo()const
{
	Armor::showFullInfo();
	std::cout << "Mana add: " << m_mana << std::endl;
}

ArmPtr WizardCloak::clone()const
{
	return ArmPtr(new WizardCloak(m_name, m_armor, m_mana));
}