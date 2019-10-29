#include <algorithm>

#include "Arena.h"

Arena::Arena(const UnitFactory* uf)
{
	for (size_t i = 0; i < arena.size(); i++)
		arena[i] = (*uf)();
}