#pragma once

#ifndef DURATION_H_
#define DURATION_H_

class Durationmeter
{
public:
	Durationmeter(int duration);
	void setStartTime(int round);
	bool isExpired(int round)const;
	bool operator==(const Durationmeter& durationmeter)const;
	operator int()const;
protected:
	int m_duration;
	int m_startTime;
};
#endif