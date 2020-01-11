#include "DamageAmplifyElem.h"
#include "../../Unit/Unit.h"

DamageAmplifyElem::DamageAmplifyElem(int damageAmplify)
	:ParamChangeElem(damageAmplify)
{

}

void DamageAmplifyElem::effectUnit(Unit& unit)
{
	unit.m_damage.changeValue(m_change);
}

void DamageAmplifyElem::uneffectUnit(Unit& unit)
{
	unit.m_damage.changeValue(-m_change);
}