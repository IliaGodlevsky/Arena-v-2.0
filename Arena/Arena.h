#ifndef ARENA_H_
#define ARENA_H_

#include "../Globals/Globals.h"

// A class, where the game cycles. Has methods and members
// that runs the game cycle
class Arena
{
	using GameStep = void(Arena::*)();
	template <int size>
	using ArenaActions = std::array<GameStep, size>;
public:
	static int getCurrentRound();
	static Arena& getInstance();
	~Arena() = default;	
	void showMiniature()const;
	void prepareArena();
	void playArena();
	void announceWinner()const;
	void showUnits()const;
private:
	bool isGameOver()const;	
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
	void playGameStep(const GameStep& method);
	void playGameSteps();
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