#pragma once

#ifndef ARENA_H_
#define ARENA_H_

#include "Unit.h"
#include "AllSpellsFactory.h"

// Singleton
class Arena
{
public:
	static int getCurrentRound();
	static Arena& getInstance();
	Arena(const Arena&) = delete;
	Arena(Arena&&) = delete;
	Arena& operator=(const Arena&) = delete;
	Arena& operator=(Arena&&) = delete;
	void showUnits()const;
public:
	bool gameOver()const;
	void newRound(); // TODO: think a new name for this method
	void castStep();
	void attackStep();
	void rewardKiller();
	void nextPlayer();
	void takeOfLosers();
public:
	void prepareUnits();
	void giveMagicToUnits(const AllItemFactory<Magic>& magicFactory);
	void giveWeaponToUnits(const AllItemFactory<Weapon>& weaponFactory);
	void giveArmorToUnits(const AllItemFactory<Armor>& armorFactory);
	void giveShieldToUnits(const AllItemFactory<Shield>& sheildFactory);
	~Arena() = default;
public:
	int setNumberOfUnits()const;
private:
	Arena();
private:
	std::vector<UnitPtr> m_units;
	int getMaxNubmerOfPlayers()const;
	int getMinNumberOfPlayers()const;
private:
	static int m_round;
private:
	UnitPtr m_unitToAttack = nullptr;
	UnitPtr m_unitToCast = nullptr;
	MagicPtr m_magicToCast = nullptr;
	size_t m_unitIndex = 0;
};

#endif