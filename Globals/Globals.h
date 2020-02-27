#ifndef GLOBALS_H
#define GLOBALS_H

#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <windows.h>
#include <array>
#include <cmath>

#include "../Exceptions/EmptyContainerException.h"
#include "../Exceptions/BadWeaponMagicException.h"
#include "../Exceptions/BadEquipmentException.h"
#include "../Exceptions/BadincomingMagicException.h"

using namespace std::placeholders;
using Strings = std::vector<std::string>;

enum TextColor : int {
	BLACK, BLUE, GREEN, CYAN, RED, MAGNETA,
	BROWN, LIGHT_GREY, DARK_GREY, LIGHT_BLUE,
	LIGHT_GREEN, LIGHT_CYAN, LIGHT_RED,
	LIGHT_MAGNETA, YELLOW, WHITE
};

enum class Signals : int { 
	DOUBLE_ATTACK = 1, ATTACK_BLOCK = 1, MAGIC_BLOCK, 
	MAGIC_REFLECT = 1, DEATH = 4, WAIT_TIME = 250
};

enum { NO, YES };

void setColor(TextColor text = WHITE, 
	TextColor background = BLACK);

class Unit;
using UnitPtr = std::shared_ptr<Unit>;
using Gladiators = std::vector<UnitPtr>;
using Units = std::vector<Gladiators>;

class Decision;
using DecisionPtr = std::shared_ptr<Decision>;

class Magic;
using MagicPtr = std::unique_ptr<Magic>;

typedef int index;

int inputNumber(const std::string& message, int upper, int lower);
bool isError(int choice, int upper, int lower);
void eatLine();

int randomNumber(int max, int min = 0);
Strings loadFromFile(const std::string& fileName);

int calculateDamageAbsorb(int armor, int damage);
double getPercentOfReduce(int armor);

void exceptionMessage(std::exception& ex);
void signal(Signals milliseconds, Signals numberOfSignals);
void checkArgs(int& upper, int& lower);

const char* const teamPlayQuest = "Do you want to play "
"in teams? <1 - yes, 0 - no>: ";
const char* const playAgainMsg = "Play again:"
" 1 - yes, 0 - no: ";

#endif
