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
	Arena(const Arena&) = delete;
	Arena(Arena&&) = delete;
	Arena& operator=(const Arena&) = delete;
	Arena& operator=(Arena&&) = delete;
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
	int setNumberOfUnits()const;
	void showMiniature()const;
private:
	Arena();	
	Units breakIntoTeams(size_t teamsNumber);
	Gladiators m_units;
	constexpr int getMaxNubmerOfPlayers()const;
	constexpr int getMinNumberOfPlayers()const;	
	Gladiators::iterator m_currentUnit;
	static int m_round;
};

enum { GAME_STEPS = 2, PREPARE_STEPS };

using GameStep = void(Arena::*)();
template <int size>
using ArenaActions = std::array<GameStep, size>;

void invoke(const GameStep& method);
void playGameStep(Arena& arena, const GameStep& method);
void playGameSteps(Arena& arena);
void announceWinner(Arena& arena);

constexpr ArenaActions<GAME_STEPS> gameSteps{
	&Arena::playCastStep,
	&Arena::playAttackStep
};

constexpr ArenaActions<PREPARE_STEPS> prepareSteps{
	&Arena::prepareUnits,
	&Arena::proposeToPlayTeams,
	&Arena::setStartUnit
};
#endif