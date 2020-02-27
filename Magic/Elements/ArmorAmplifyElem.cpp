#include "ArmorAmplifyElem.h"
#include "../../Unit/Unit.h"

ArmorAmplifyElem::ArmorAmplifyElem(int armorAmplify)
	: ParamChangeElem(armorAmplify)
{

}

void ArmorAmplifyElem::effectUnit(Unit& unit)
{
	unit.m_armor.changeAdditaionalValue(m_change);
}

void ArmorAmplifyElem::uneffectUnit(Unit& unit)
{
	unit.m_armor.changeAdditaionalValue(-m_change);
}

bool ArmorAmplifyElem::isEqual(const ParamChangeElemPtr& element)const
{
	return canCast<ArmorAmplifyElem*>(element)
		&& ParamChangeElem::isEqual(element);
}

ParamChangeElemPtr ArmorAmplifyElem::clone()const
{
	return ParamChangeElemPtr(new ArmorAmplifyElem(m_change));
}

void ArmorAmplifyElem::showInfo()const
{
	std::cout << "Adds " << m_change << " armor";
}