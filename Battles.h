#ifndef BATTLES_H_
#define BATTLES_H_

class Battles
{
public:
	explicit Battles(int value);
	void ChangeValue(int value);
	operator int()const;
protected:
	int value;
};
#endif