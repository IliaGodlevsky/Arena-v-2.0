#pragma once

#ifndef ARENA_H_
#define ARENA_H_

#include <vector>

#include "Unit.h"

// Singleton
class Arena
{
public:
	static int CurrentRound();
	static Arena& GetInstance();
	Arena(const Arena&) = delete;
	Arena(Arena&&) = delete;
	Arena& operator=(const Arena&) = delete;
	Arena& operator=(Arena&&) = delete;
	void TakeOfLosers();
	bool GameOver()const;
	void GameCycle();
	~Arena();
private:
	int SetNumberOfUnits()const;
	void SetArenaConsistance();
	void FillWeaponary();
	void FillArmory();
	void FillSpells();
	Arena();
private: // vectors
	std::vector<Weapon*> weapons;
	std::vector<Armor*> armors;
	std::vector<Shield*> shields;
	std::vector<MagicPtr> spells;
	std::vector<Decision*> decisions;
	std::vector<UnitPtr> arena;
private:
	const int MIN_PLAYERS = 2;
	const int MAX_PLAYERS = 5;
	Decision* human;
	Decision* computer;
	static int round;
};

#endif