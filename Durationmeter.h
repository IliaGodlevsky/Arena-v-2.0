#pragma once

#ifndef DURATION_H_
#define DURATION_H_

class Durationmeter
{
public:
	Durationmeter(int duration);
	void SetStartTime(int round);
	bool IsExpired(int round)const;
	bool operator==(const Durationmeter& d)const;
	operator int()const;
protected:
	int duration;
	int start_time;
};
#endif