#pragma once

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
private:
	int SetNumberOfUnits()const;
	Arena();
private:
	std::vector<Decision*> decisions;
	std::vector<Unit*> arena;
	static int round;
};