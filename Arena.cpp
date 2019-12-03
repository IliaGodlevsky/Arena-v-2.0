#include <iostream>
#include <ctime>

#include "Arena.h"
#include "MagicFactory.h"
#include "WeaponFactory.h"
#include "ArmorFactory.h"

int Arena::round_ = 0;

Arena::Arena() :
	spellFactory({ new DamageBuffFactory(),new ArmorBuffFactory(),
		new ArmorAndDamageBuffFactory(), new OffsetDamageBuffFactory() }),
	weaponFactory({ new SwordFactory(),new AxeFactory() }),
	armorFactory({ new ArmorFactory(),new MailFactory(),
		new WizardCloakFactory(),new LegionerChainsFactory() })
{
	std::srand(std::time(nullptr));
	arena_.resize(setNumberOfUnits());
	// Give items to units
	// Give units names
}

void Arena::giveOutSpells()
{
	for (size_t i = 0; i < arena_.size(); i++)
		arena_[i]->spell_book.TakeMagic(spellFactory.createItemFromFactory());
}


int Arena::setNumberOfUnits()const
{
	return input("Set number of players: ",
		MAX_PLAYERS_, MIN_PLAYERS_);
}

int Arena::currentRound()
{
	return round_;
}

Arena& Arena::getInstance()
{
	static Arena instance;
	return instance;
}

void Arena::showUnits()const
{
	for (size_t i = 0; i < arena_.size(); i++)
	{
		std::cout << i + 1 << ". ";
		arena_[i]->ShowFullInfo();
	}
}

void Arena::takeOfLosers()
{
	for (size_t i = 0; i < arena_.size(); i++)
	{
		if (!arena_[i]->IsAlive())
		{
			arena_.erase(arena_.begin() + i);
			i--;
		}
	}
}

bool Arena::gameOver()const
{
	return arena_.size() == 1;
}

void Arena::castStep()
{
	showUnits();
	magicToSpell_ = arena_[indexNumber_]->ChooseMagicToCast();
	unitToCast_ = arena_[indexNumber_]->ChooseUnitToCast(magicToSpell_);
	arena_[indexNumber_]->Spell(*unitToCast_, magicToSpell_);
}

void Arena::attackStep()
{
	showUnits();
	unitToAttack_ = arena_[indexNumber_]->ChooseUnitToAttack();
	arena_[indexNumber_]->Injure(*unitToAttack_);
}

void Arena::rewardKiller()
{
	if (!unitToCast_->IsAlive())
		arena_[indexNumber_]->LevelUp();
}

void Arena::nextPlayer()
{
	indexNumber_++;
	if (indexNumber_ >= arena_.size())
	{
		indexNumber_ = 0;
		round_++;
	}
}

void Arena::scan()
{
	for (size_t i = 0; i < arena_.size(); i++)
		arena_[i]->Scan();
}