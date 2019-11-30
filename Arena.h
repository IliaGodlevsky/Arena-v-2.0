#pragma once

#ifndef ARENA_H_
#define ARENA_H_

#include "Unit.h"
#include "MagicFactory.h"

// Singleton
class Arena
{
public:
	static int currentRound();
	static Arena& getInstance();
	Arena(const Arena&) = delete;
	Arena(Arena&&) = delete;
	Arena& operator=(const Arena&) = delete;
	Arena& operator=(Arena&&) = delete;
	void takeOfLosers();
	void showUnits()const;
public:
	bool gameOver()const;
	void scan();
	void castStep();
	void attackStep();
	void rewardKiller();
	void nextPlayer();
	~Arena();
public:
	int setNumberOfUnits()const;
	Arena();
private:
	void giveOutSpells();
private: // vectors
	std::vector<Weapon*> weapons_;
	std::vector<Armor*> armors_;
	std::vector<Shield*> shields_;
	std::vector<Unit*> arena_;
private:
	const int MIN_PLAYERS_ = 2;
	const int MAX_PLAYERS_ = 5;
	static int round_;
private:
	BuffFactory buffFactory;
	Unit* unitToAttack_ = nullptr;
	Unit* unitToCast_ = nullptr;
	MagicPtr magicToSpell_ = nullptr;
	size_t indexNumber_ = 0;
};

#endif