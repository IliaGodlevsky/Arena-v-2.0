#include <cmath>

#include "Vitals.h"

Vitals::Vitals(int value, int max_value,
	int value_regeneration)
	: value(value), max_value(max_value),
	value_regeneration(value_regeneration)
{
	FixOverflow();
}

Vitals Vitals::operator++(int i)
{
	Vitals temp = *this;
	value += value_regeneration;
	FixOverflow();
	return temp;
}

Vitals Vitals::operator-(int value)const
{
	Vitals temp = *this;
	fdim(temp.value, value);
	return temp;
}

Vitals Vitals::operator+(const Vitals& vit)const
{
	int val = value + vit.value;
	int max_val = max_value + vit.max_value;
	int regen = value_regeneration + vit.value_regeneration;
	Vitals temp(val, max_val, regen);
	temp.FixOverflow();
	return temp;
}

Vitals Vitals::operator-(const Vitals& vit)const
{
	int val = fdim(value,vit.value);
	int max_val = fdim(max_value, vit.max_value);
	int regen = value_regeneration - vit.value_regeneration;
	return Vitals(val, max_val, regen);
}

void Vitals::ChangeRegeneration(int regen)
{
	value_regeneration += regen;
}

bool Vitals::IsDead()const
{
	return value == DEAD_LINE;
}

void Vitals::FixOverflow()
{
	if (value > max_value)
		value = max_value;
	if (value < DEAD_LINE)
		value = DEAD_LINE;
}

bool Vitals::operator>(int damage)const
{
	return value > damage;
}

bool Vitals::operator<(int damage)const
{
	return value < damage;
}

bool Vitals::operator==(int damage)const
{
	return value == damage;
}

bool Vitals::operator!=(int damage)const
{
	return value != damage;
}

bool Vitals::operator>=(int damage)const
{
	return value >= damage;
}

bool Vitals::operator<=(int damage)const
{
	return value <= damage;
}