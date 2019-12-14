#include "DebuffMagic.h"
#include "DebuffMagicFactory.h"

DamageDebuffFactory::DamageDebuffFactory()
{
	m_items.push_back(MagicPtr(new DamageDebuff("Weakness", WEAKNESS_MANA_COST, 
		WEAKNESS_DURATION, WEAKNESS_DAMAGE_REDUCE)));
	m_items.push_back(MagicPtr(new DamageDebuff("Tiredness", TIREDNESS_MANA_COST, 
		TIREDNESS_DURATION, TIREDNESS_DAMAGE_REDUCE)));
}

int DamageDebuffFactory::getChanceOfCreation()const
{
	return 40;
}

ArmorDebuffFactory::ArmorDebuffFactory()
{
	m_items.push_back(MagicPtr(new ArmorDebuff("Corruption", CORRUPTION_MANA_COST,
		CORRUPTION_DURATION, CORRUPTION_ARMOR_REDUCE)));
	m_items.push_back(MagicPtr(new ArmorDebuff("Corrosion",CORROSION_MANA_COST,
		CORROSION_DURATION,CORROSION_ARMOR_REDUCE)));
}

int ArmorDebuffFactory::getChanceOfCreation()const
{
	return 40;
}

ArmorAndDamageDebuffFactory::ArmorAndDamageDebuffFactory()
{
	m_items.push_back(MagicPtr(new ArmorAndDamageDebuff("Curse", CURSE_MANA_COST, 
		CURSE_DURATION, CURSE_ARMOR_REDUCE, CURSE_DAMAGE_REDUCE)));
	m_items.push_back(MagicPtr(new ArmorAndDamageDebuff("Mutilation", MUTILATION_MANA_COST, 
		MUTILATION_DURATION, MUTILATION_ARMOR_REDUCE, MUTILATION_DAMAGE_REDUCE)));
}

int ArmorAndDamageDebuffFactory::getChanceOfCreation()const
{
	return 15;
}

SilenceFactory::SilenceFactory()
{
	m_items.push_back(MagicPtr(new Silence("Silence", SILENCE_MANA_COST, SILENCE_DURATION)));
	m_items.push_back(MagicPtr(new Silence("Hollow silence", HOLLOW_SILENCE_MANA_COST, HOLLOW_SILENCE_DURATION)));
}

int SilenceFactory::getChanceOfCreation()const
{
	return 5;
}