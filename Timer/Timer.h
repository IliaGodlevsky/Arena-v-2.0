#pragma once

#ifndef DURATION_H_
#define DURATION_H_

class Timer
{
public:
	Timer(int duration);
	void setStartTime(int round);
	bool isExpired(int round)const;
	bool operator==(const Timer& durationmeter)const;
	operator int()const;
protected:
	int m_duration;
	int m_startTime;
};
#endif