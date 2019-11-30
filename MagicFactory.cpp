#include <random>

#include "MagicFactory.h"
#include "Magic.h"

int randomIndex(int arraySize) { return std::rand() % arraySize; }

MagicFactory::MagicFactory()
	:spells(0)
{

}

MagicPtr MagicFactory::createMagic()
{
	if (buffsGaved >= spells.size())
		return nullptr;
	int index = randomIndex(spells.size() - buffsGaved);
	MagicPtr t = spells[index]->Clone();
	spells.erase(spells.begin() + index);
	buffsGaved++;
	return t;
}

DamageBuffFactory::DamageBuffFactory()
{
	spells.push_back(MagicPtr(new DamageBuff("Strength",
		STRENGTH_MANA_COST, STRENGTH_DURATION, STRENGTH_AMPLIFY_DAMAGE)));
	spells.push_back(MagicPtr(new DamageBuff("Power", POWER_MANA_COST,
		POWER_DURATION, POWER_AMPLFY_DAMAGE)));
}

int DamageBuffFactory::chance()const
{
	return CHANCE;
}

ArmorBuffFactory::ArmorBuffFactory()
{
	spells.push_back(MagicPtr(new ArmorBuff("Stone skin", STONE_SKIN_MANA_COST,
		STONE_SKIN_DURATION, STONE_SKIN_AMPLIFY_ARMOR)));
	spells.push_back(MagicPtr(new ArmorBuff("Holy shield", HOLY_SHIELD_MANA_COST,
		HOLY_SHIELD_DURATION, HOLY_SHIELD_AMPLIFY_ARMOR)));
}

int ArmorBuffFactory::chance()const
{
	return CHANCE;
}

ArmorAndDamageBuffFactory::ArmorAndDamageBuffFactory()
{
	spells.push_back(MagicPtr(new ArmorAndDamageBuff("God armor",
		GOD_ARMOR_MANA_COST, GODS_ARMOR_DURATION,
		GODS_ARMOR_AMPLIFY_ARMOR, GODS_ARMOR_AMPLIFY_DAMAGE)));
	spells.push_back(MagicPtr(new ArmorAndDamageBuff("Bless", BLESS_MANA_COST,
		BLESS_DURATION, BLESS_AMPLIFY_ARMOR, BLESS_AMPLIFY_DAMAGE)));
}

int ArmorAndDamageBuffFactory::chance()const
{
	return CHANCE;
}

OffsetDamageBuffFactory::OffsetDamageBuffFactory()
{
	spells.push_back(MagicPtr(new OffsetDamageBuff("Berserk", BERSERK_MANA_COST,
		BERSERK_DURATION, BERSERK_REDUCE_ARMOR, BERSERK_AMPLIFY_DAMAGE)));
	spells.push_back(MagicPtr(new OffsetDamageBuff("Rage", RAGE_MANA_COST,
		RAGE_DURATION, RAGE_REDUCE_ARMOR, RAGE_AMPLIFY_DAMAGE)));
}

int OffsetDamageBuffFactory::chance()const
{
	return CHANCE;
}


BuffFactory::BuffFactory(std::initializer_list<MagicFactory*> factList)
	: factories_(factList), chances_(factList.size())
{
	for (size_t i = 0; i < factList.size(); i++)
	{
		chances_[i] = factories_[i]->chance();
		totalChances_ += factories_[i]->chance();
	}
}

MagicPtr BuffFactory::createMagic()
{
	int ch = chance(0, totalChances_);
	int index = transformChanceToIndex(ch);
	MagicFactory* factory = factories_[index];
	while (nullptr == factory->createMagic())
	{
		totalChances_ -= chances_[index];
		chances_.erase(chances_.begin() + index);
		factories_.erase(factories_.begin() + index);
		ch = chance(0, totalChances_);
		index = transformChanceToIndex(ch);
		factory = factories_[index];
	}
	return factory->createMagic();
}

int BuffFactory::transformChanceToIndex(int chance)const
{
	int lower = 0, upper = 0;
	for (int i = 0; i < chances_.size(); i++)
	{
			upper += chances_[i];
			if (inBounds(lower, upper, chance))
				return i;
			else
				lower += chances_[i];
	}
}

bool BuffFactory::inBounds(int lower, int upper, int chance)const
{
	if (chance >= lower && chance < upper)
		return true;
	else
		return false;
}

int BuffFactory::chance(int lowerBound, int upperBound)const
{
	std::random_device seed;
	std::mt19937 generator(seed());
	std::uniform_int_distribution<int>
		distributor(lowerBound, upperBound);
	return distributor(generator);
}

BuffFactory::~BuffFactory()
{
	for (size_t i = 0; i < factories_.size(); i++)
		delete factories_[i];
}