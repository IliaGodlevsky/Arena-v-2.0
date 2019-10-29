#include <iostream>
#include <cmath>
#include <algorithm>

#include "Vitals.h"

Vital::Vital(int points, int max_points,
	int points_regen, int max_points_regen)
	: points(points), max_points(max_points),
	points_regen(points_regen), 
	max_points_regen(max_points_regen)
{
	fix_overflow(this->points, this->max_points);
	fix_overflow(this->points_regen, 
		this->max_points_regen);
}

Vital Vital::operator++(int i)
{
	Vital temp = *this;
	points += points_regen;
	fix_overflow(points, max_points);
	return temp;
}

Vital Vital::operator--(int i)
{
	Vital temp = *this;
	points = fdim(points, points_regen);
	return temp;
}

Vital Vital::operator+(const Vital& vital)const
{
	return Vital(points + vital.points * 0.15,
		max_points + vital.max_points * 0.1, 
		points_regen + 1, max_points_regen + 2);
}

Vital Vital::operator-(int damage)const
{
	return Vital(fdim(points, damage), max_points, 
		points_regen, max_points_regen);
}
Vital Vital::operator+(int heal)const
{
	return Vital(points + heal, max_points, 
		points_regen, max_points_regen);
}

bool Vital::operator==(const Vital& vital)const
{
	return points == vital.points;
}

bool Vital::operator>(const Vital& vital)const
{
	return points > vital.points;
}

bool Vital::empty()const
{
	return points == 0;
}