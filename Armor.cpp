#include <iostream>

#include "Armor.h"
#include "Unit.h"

Armor::Armor(std::string name, int armor)
	: armor(armor), name(name)
{

}

void Armor::PutOn(Unit& unit)const
{
	unit.armor.ChangeValue(armor);
}

void Armor::PutOff(Unit& unit)const
{
	unit.armor.ChangeValue(-armor);
}

void Armor::ShowShortInfo()const
{
	std::cout << "<" << name << ">\n";
}

void Armor::ShowFullInfo()const
{
	std::cout << "Name: " << name << std::endl;
	std::cout << "Armor: " << armor << std::endl;
}

Mail::Mail(std::string name, int armor, Vitals health)
	: Armor(name, armor), health(health)
{

}

void Mail::PutOn(Unit& unit)const
{
	Armor::PutOn(unit);
	unit.health = unit.health + health;
}

void Mail::PutOff(Unit& unit)const
{
	Armor::PutOff(unit);
	unit.health = unit.health - health;
}

void Mail::ShowFullInfo()const
{
	Armor::ShowFullInfo();
	std::cout << "Health add: " << health << std::endl;
}

WizardCloak::WizardCloak(std::string name, int armor, Vitals mana)
	: Armor(name, armor), mana(mana)
{

}

void WizardCloak::PutOn(Unit& unit)const
{
	unit.mana = unit.mana + mana;
}

void WizardCloak::PutOff(Unit& unit)const
{
	unit.mana = unit.mana - mana;
}

void WizardCloak::ShowFullInfo()const
{
	Armor::ShowFullInfo();
	std::cout << "Mana add: " << mana << std::endl;
}

LegionerChains::LegionerChains(std::string name, int armor,
	Vitals health, Vitals mana) : Armor(name, armor),
	health(health), mana(mana)
{

}

void LegionerChains::PutOn(Unit& unit)const
{
	Armor::PutOn(unit);
	unit.health = unit.health + health;
	unit.mana = unit.mana + mana;
}

void LegionerChains::PutOff(Unit& unit)const
{
	Armor::PutOff(unit);
	unit.health = unit.health - health;
	unit.mana = unit.mana - mana;
}

void LegionerChains::ShowFullInfo()const
{
	Armor::ShowFullInfo();
	std::cout << "Health add: " << health << std::endl;
	std::cout << "Mana add: " << mana << std::endl;
}