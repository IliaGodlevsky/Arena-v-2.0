#ifndef TIMER_H_
#define TIMER_H_

/* A class that is responsible for 
duration of states or magic */
class Timer
{
public:
	explicit Timer(int duration);
	Timer(int duration, int startTime);
	Timer() = default;
	Timer(const Timer&) = default;
	Timer(Timer&&) = default;
	Timer& operator= (const Timer&) = default;
	Timer& operator= (Timer&&) = default;
	void setStartTime(int round);
	bool isExpired(int round)const;
	bool operator==(const Timer& durationmeter)const;
	int getDuration()const;
	int getStartTime()const;
protected:
	int m_duration = 0;
	int m_startTime = 0;
};
#endif