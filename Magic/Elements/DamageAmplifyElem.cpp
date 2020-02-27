#include "DamageAmplifyElem.h"
#include "../../Unit/Unit.h"

DamageAmplifyElem::DamageAmplifyElem(int damageAmplify)
	:ParamChangeElem(damageAmplify)
{

}

void DamageAmplifyElem::effectUnit(Unit& unit)
{
	unit.m_damage.changeAdditaionalValue(m_change);
}

void DamageAmplifyElem::uneffectUnit(Unit& unit)
{
	unit.m_damage.changeAdditaionalValue(-m_change);
}

bool DamageAmplifyElem::isEqual(const ParamChangeElemPtr& element)const
{
	return canCast<DamageAmplifyElem*>(element)
		&& ParamChangeElem::isEqual(element);
}

ParamChangeElemPtr DamageAmplifyElem::clone()const
{
	return ParamChangeElemPtr(new DamageAmplifyElem(m_change));
}

void DamageAmplifyElem::showInfo()const
{
	std::cout << "Adds " << m_change << " damage";
}