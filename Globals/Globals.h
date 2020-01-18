#ifndef GLOBALS_H
#define GLOBALS_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>
#include <windows.h>

#include "../Messager/Messager.h"
#include "../Exceptions/EmptyContainerException.h"
#include "../Exceptions/BadWeaponMagicException.h"
#include "../Exceptions/BadEquipmentException.h"
#include "../Exceptions/BadincomingMagicException.h"

#define YES true
#define NO !YES
#define NULLPTR nullptr

enum TextColor
{
	BLACK = 0,
	BLUE = 1,
	GREEN = 2,
	CYAN = 3,
	RED = 4,
	MAGNETA = 5,
	BROWN = 6,
	LIGHT_GREY = 7,
	DARK_GREY = 8,
	LIGHT_BLUE = 9,
	LIGHT_GREEN = 10,
	LIGHT_CYAN = 11,
	LIGHT_RED = 12,
	LIGHT_MAGNETA = 13,
	YELLOW = 14,
	WHITE = 15
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

void exceptionMessage(std::exception& ex);

const char* const teamPlayQuest = "Do you want to play "
"in teams? <1 - yes, 0 - no>: ";

#endif
