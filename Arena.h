#pragma once

#ifndef ARENA_H_
#define ARENA_H_

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
	void ShowUnits()const;
public:
	bool GameOver()const;
	void Scan();
	void CastStep();
	void AttackStep();
	void RewardKiller();
	void NextPlayer();
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
	std::vector<Unit*> arena;
private:
	const int MIN_PLAYERS = 2;
	const int MAX_PLAYERS = 5;
	static int round;
private:
	Unit* unit_to_attack = nullptr;
	Unit* unit_to_cast = nullptr;
	MagicPtr magic_to_spell = nullptr;
	size_t player_index_number = 0;
};

#endif