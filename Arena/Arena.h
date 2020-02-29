#ifndef ARENA_H_
#define ARENA_H_

#include "../Globals/Globals.h"

// A class, where the game cycles. Has methods and members
// that runs the game cycle
class Arena
{
public:
	static int getCurrentRound();
	static Arena& getInstance();
	~Arena() = default;
	bool isGameOver()const;
	void showUnits()const;
	void goNewRound();
	void playCastStep();
	void playAttackStep();
	void rewardKiller(UnitPtr victim);
	void goNextUnit();
	void takeOfLosers();
	void prepareUnits();
	void proposeToPlayTeams();
	void setStartUnit();
	void setNumberOfUnits();
	void showMiniature()const;
private:
	Arena(const Arena&) = delete;
	Arena(Arena&&) = delete;
	Arena& operator=(const Arena&) = delete;
	Arena& operator=(Arena&&) = delete;
	Arena();	
	Units breakIntoTeams(size_t teamsNumber);
	Gladiators m_units;
	Gladiators::iterator m_currentUnit;
	static int m_round;
};

#endif