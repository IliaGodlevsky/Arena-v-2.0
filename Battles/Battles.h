#ifndef BATTLES_H_
#define BATTLES_H_

class Battles
{
public:
	explicit Battles(int value);
	void changeValue(int value);
	operator int()const;
protected:
	int m_value;
};
#endif