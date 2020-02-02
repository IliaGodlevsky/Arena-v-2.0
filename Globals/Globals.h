#ifndef GLOBALS_H
#define GLOBALS_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <windows.h>

#include "../Exceptions/EmptyContainerException.h"
#include "../Exceptions/BadWeaponMagicException.h"
#include "../Exceptions/BadEquipmentException.h"
#include "../Exceptions/BadincomingMagicException.h"
#include "../Exceptions/ArenaUninterseptedException.h"

#define YES true
#define NO !YES
#define NULLPTR nullptr
#define is == 

enum TextColor {
	BLACK, BLUE, GREEN, CYAN, RED, MAGNETA,
	BROWN, LIGHT_GREY, DARK_GREY, LIGHT_BLUE,
	LIGHT_GREEN, LIGHT_CYAN, LIGHT_RED,
	LIGHT_MAGNETA, YELLOW, WHITE
};

enum Signals { 
	ATTACK_BLOCK = 1, MAGIC_BLOCK, 
	MAGIC_REFLECT, DEATH, WAIT_TIME = 250
};

void setColor(TextColor text = WHITE, TextColor background = BLACK);

class Unit;
using UnitPtr = std::shared_ptr<Unit>;
using Gladiators = std::vector<UnitPtr>;

class Decision;
using DecisionPtr = std::shared_ptr<Decision>;

class Magic;
using MagicPtr = std::unique_ptr<Magic>;

typedef unsigned index;

int inputNumber(const std::string& message, int upper, int lower);
bool isError(int choice, int upper, int lower);
void eatLine();

int randomNumber(int max, int min = 0);
std::vector<std::string> loadFromFile(const std::string& fileName);

int calculateDamageAbsorb(int armor, int damage);
double getPercentOfReduce(int armor);

void exceptionMessage(std::exception& ex);
void myTerminate();
void signal(int milliseconds, int numberOfSignals);

const char* const teamPlayQuest = "Do you want to play "
"in teams? <1 - yes, 0 - no>: ";

#endif
