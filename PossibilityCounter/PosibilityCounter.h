#ifndef POSIBILITY_H_
#define POSIBILITY_H_

/* A class that is responsible for 
the possibilities in the game*/
class PosibilityCounter
{
public:
	explicit PosibilityCounter(int posibility);
	PosibilityCounter() = delete;
	PosibilityCounter(const PosibilityCounter&) = default;
	PosibilityCounter(PosibilityCounter&&) = default;
	PosibilityCounter& operator=(const PosibilityCounter&) = default;
	PosibilityCounter& operator=(PosibilityCounter&&) = default;
	bool operator==(const PosibilityCounter& counter)const;
	int getPosibility()const;
	operator bool()const;
private:
	constexpr int getMaxPropability()const;
	int m_posibility = 0;
};

#endif