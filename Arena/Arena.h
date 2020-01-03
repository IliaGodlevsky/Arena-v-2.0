#pragma once

#ifndef ARENA_H_
#define ARENA_H_

#include <thread>

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
	void rewardKiller(UnitPtr victim);
	void goNextUnit();
	void takeOfLosers();
public:
	void prepareUnits();
	void proposeToPlayTeams();
	~Arena() = default;
public:
	int setNumberOfUnits()const;
private:
	void showMiniature()const;
	std::vector<Gladiators> breakIntoTeams(size_t teamsNumber);
	void setAllies(std::vector<Gladiators>& teams)const;
	void pushAlliesToArena(const std::vector<Gladiators>& teams);
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
private:
	std::vector<std::string> m_reserveNames =
	{
		"Bill","Glen","Mark","Gven","Sally","Opera",
		"Dgill","Sam","Oliver","Gvinett","Tony","Moody",
		"Sigma","Anna","Vector","Trench","Rex","Paul",
		"Bruno","Silvia","John","Tirion","Mortal","Wolf",
		"Elizabeth","Unberto","Izabell","Oxford","Mark"
	};
};

#endif