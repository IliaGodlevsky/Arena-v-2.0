#ifndef ARENA_DELEGATE_H_
#define ARENA_DELEGATE_H_

#include "Arena.h"

enum {
	GAME_STEPS = 2, PREPARE_STEPS = 4
};

using GameStep = void(Arena::*)();
template <int size>
using ArenaActions = std::array<GameStep, size>;

template <typename Method>
void invoke(const Method& method)
{
	(Arena::getInstance().*method)();
}
void playGameStep(Arena& arena, 
	const GameStep& method);
void playGameSteps(Arena& arena);
void announceWinner(Arena& arena);

constexpr ArenaActions<PREPARE_STEPS> prepareSteps{
	&Arena::setNumberOfUnits,
	&Arena::prepareUnits,
	&Arena::proposeToPlayTeams,
	&Arena::setStartUnit
};

#endif