#pragma once

#ifndef VITALS_H_
#define VITALS_H_

#include "Magic.h"

template <typename Type>
void fix_overflow(Type& value, Type& max_value);

class Vital
{
public:
	Vital() = default;
	Vital(int points, int max_points,
		int points_regen, int max_points_regen);
	Vital(const Vital&) = default;
	Vital(Vital&&) = default;
	Vital& operator=(const Vital&) = default;
	Vital& operator=(Vital&&) = default;
	Vital operator++(int i);
	Vital operator--(int i);
	Vital operator+(const Vital&)const;
	Vital operator-(int)const;
	Vital operator+(int)const;
	bool operator==(const Vital&)const;
	bool operator>(const Vital&)const;
	bool empty()const;
private:
	int points;
	int max_points;
	int points_regen;
	int max_points_regen;
};

template <typename Type>
inline void fix_overflow(Type& value, 
	Type& max_value)
{
	if (value >= max_value)
		value = max_value;
}
#endif