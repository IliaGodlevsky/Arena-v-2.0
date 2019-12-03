#include <iostream>

#include "Sheild.h"
#include "Unit.h"

Shield::Shield(std::string name, int armor,
	int reflect_chance)
	: Armor(name, armor), 
	reflect_chance(reflect_chance)
{

}

void Shield::PutOn(Unit& unit)const
{
	Armor::PutOn(unit);
}

void Shield::PutOff(Unit& unit)const
{
	Armor::PutOff(unit);
}

void Shield::ShowFullInfo()const
{
	Armor::ShowFullInfo();
	std::cout << "Reflect chance: " << reflect_chance << std::endl;
}

bool Shield::Reflect()const
{
	return PosibilityCounter(reflect_chance);
}



TowerShield::TowerShield(std::string name, int armor,
	Vitals health, int reflect_chance)
	: Shield(name, armor,reflect_chance), health(health)
{

}

void TowerShield::PutOn(Unit& unit)const
{
	Shield::PutOn(unit);
	unit.health = unit.health + health;
}

void TowerShield::PutOff(Unit& unit)const
{
	Shield::PutOff(unit);
	unit.health = unit.health - health;
}

void TowerShield::ShowFullInfo()const
{
	Shield::ShowFullInfo();
	std::cout << "Health add: " << health << std::endl;
}


LegionShield::LegionShield(
	std::string name, 
	int armor,
	Vitals health,
	Vitals mana, 
	int reflcet_chance)
	: Shield(name, armor, reflcet_chance), 
	health(health),
	mana(mana)
{

}

void LegionShield::PutOn(Unit& unit)const
{
	Shield::PutOn(unit);
	unit.health = unit.health + health;
	unit.mana = unit.mana + health;
}

void LegionShield::PutOff(Unit& unit)const
{
	Shield::PutOff(unit);
	unit.health = unit.health - health;
	unit.mana = unit.mana - health;
}

void LegionShield::ShowFullInfo()const
{
	Shield::ShowFullInfo();
	std::cout << "Health add: " << health << std::endl;
	std::cout << "Mana add: " << mana << std::endl;
}

