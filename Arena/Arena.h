#pragma once

#ifndef ARENA_H_
#define ARENA_H_

#include "../Globals/Globals.h"
#include "../Factories/UnitFactory/UnitFactory.h"

// A class, where the game cycles. Has methods and members
// that runs the game cycle
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
	~Arena() = default;
public:
	int setNumberOfUnits()const;
private:
	Arena();
private:
	Gladiators m_units;
	constexpr int getMaxNubmerOfPlayers()const;
	constexpr int getMinNumberOfPlayers()const;
private:
	static int m_round;
private:
	UnitPtr m_unitToAttack = nullptr;
	UnitPtr m_unitToCast = nullptr;
	MagicPtr m_magicToCast = nullptr;
	index m_unitIndex = 0;
};

#endif