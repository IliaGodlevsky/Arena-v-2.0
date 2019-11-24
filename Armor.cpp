#include "Armor.h"
#include "Unit.h"

Armor::Armor(int armor)
	: armor(armor)
{

}

void Armor::PutOn(UnitPtr unit)const
{
	unit->armor.ChangeValue(armor.Value());
}

void Armor::PutOff(UnitPtr unit)const
{
	unit->armor.ChangeValue(-armor.Value());
}

Mail::Mail(int armor, Vitals health)
	: Armor(armor), health(health)
{

}

void Mail::PutOn(UnitPtr unit)const
{
	Armor::PutOn(unit);
	unit->health = unit->health + health;
}

void Mail::PutOff(UnitPtr unit)const
{
	Armor::PutOff(unit);
	unit->health = unit->health - health;
}

WizardCloak::WizardCloak(int armor, Vitals mana)
	: Armor(armor), mana(mana)
{

}

void WizardCloak::PutOn(UnitPtr unit)const
{
	unit->mana = unit->mana + mana;
}

void WizardCloak::PutOff(UnitPtr unit)const
{
	unit->mana = unit->mana - mana;
}