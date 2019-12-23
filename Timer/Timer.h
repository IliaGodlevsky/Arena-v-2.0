#ifndef TIMER_H_
#define TIMER_H_

class Timer
{
public:
	explicit Timer(int duration);
	Timer(const Timer&) = default;
	Timer(Timer&&) = default;
	Timer& operator= (const Timer&) = default;
	Timer& operator= (Timer&&) = default;
	void setStartTime(int round);
	bool isExpired(int round)const;
	bool operator==(const Timer& durationmeter)const;
	int getDuration()const;
protected:
	int m_duration;
	int m_startTime;
};
#endif