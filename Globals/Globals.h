#ifndef GLOBALS_H
#define GLOBALS_H

#include <memory>
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

#include "../Messager/Messager.h"
#include "../Exceptions/EmptyContainerException.h"
#include "../Exceptions/BadWeaponMagicException.h"
#include "../Exceptions/BadEquipmentException.h"
#include "../Exceptions/BadincomingMagicException.h"

#define YES true
#define NO !YES
#define NULLPTR nullptr

class Unit;
using UnitPtr = std::shared_ptr<Unit>;
using Gladiators = std::vector<UnitPtr>;

class Decision;
using DecisionPtr = std::shared_ptr<Decision>;

class Magic;
using MagicPtr = std::unique_ptr<Magic>;

typedef unsigned index;

constexpr int ZERO_DURATION = 0;
constexpr int ZERO_MANA_COST = 0;
constexpr int ZERO_CRITIAL_PROBABILITY = 0;

int inputNumber(const std::string& message, int upper, int lower);
bool isError(int choice, int upper, int lower);
void eatLine();

int randomNumber(int max, int min = 0);
std::vector<std::string> loadFromFile(const std::string& fileName);

void exceptionMessage(std::exception& ex);

#endif
