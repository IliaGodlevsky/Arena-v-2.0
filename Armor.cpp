#include "Armor.h"

Armor::Armor(int armor)
	: armor(armor)
{

}

Mail::Mail(int armor, Vitals health)
	: Armor(armor), health(health)
{

}

void Mail::PutOn(UnitPtr unit)const
{
	unit->armor.ChangeValue(armor.Value());
	unit->health = unit->health + health;
}

void Mail::PutOff(UnitPtr unit)const
{
	unit->armor.ChangeValue(-armor.Value());
	unit->health = unit->health - health;
}

WizardCloak::WizardCloak(int armor, Vitals mana)
	: Armor(armor), mana(mana)
{

}

void WizardCloak::PutOn(UnitPtr unit)const
{

}

void WizardCloak::PutOff(UnitPtr unit)const
{

}