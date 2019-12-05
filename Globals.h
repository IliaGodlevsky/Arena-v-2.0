#ifndef GLOBALS_H
#define GLOBALS_H

#include <memory>
#include <string>
#include <vector>

class Unit;
using UnitPtr = std::shared_ptr<Unit>;
using Gladiators = std::vector<UnitPtr>;

class Decision;

class Magic;
using MagicPtr = std::unique_ptr<Magic>;
using Spells = std::vector<MagicPtr>;

class Weapon;
using WeaponPtr = std::unique_ptr<Weapon>;

class Armor;
using ArmPtr = std::unique_ptr<Armor>;

class Shield;
using ShieldPtr = std::unique_ptr<Shield>;

constexpr int ZERO_DURATION = 0;
constexpr int ZERO_MANA_COST = 0;

int inputNumber(const std::string& message, int upper, int lower);
bool isError(int choice, int upper, int lower);
void eatLine();

inline int randomIndex(int arraySize);

#endif
