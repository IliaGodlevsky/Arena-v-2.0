#pragma once

#ifndef ARENA_H_
#define ARENA_H_

#include "Unit.h"
#include "ItemFactory.h"

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
	bool isGameOver()const;
	void goNewRound();
	void playCastStep();
	void playAttackStep();
	void rewardKiller();
	void goNextUnit();
	void takeOfLosers();
public:
	void prepareUnits();
	void giveMagicToUnits(const ItemFactory<Magic>& magicFactory);
	void giveWeaponToUnits(const ItemFactory<Weapon>& weaponFactory);
	void giveArmorToUnits(const ItemFactory<Armor>& armorFactory);
	void giveShieldToUnits(const ItemFactory<Shield>& sheildFactory);
	~Arena() = default;
public:
	int setNumberOfUnits()const;
private:
	Arena();
private:
	Gladiators m_units;
	int getMaxNubmerOfPlayers()const;
	int getMinNumberOfPlayers()const;
private:
	static int m_round;
private:
	UnitPtr m_unitToAttack = nullptr;
	UnitPtr m_unitToCast = nullptr;
	MagicPtr m_magicToCast = nullptr;
	index m_unitIndex = 0;
};

#endif