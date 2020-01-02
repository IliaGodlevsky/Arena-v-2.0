#ifndef BATTLES_H_
#define BATTLES_H_

/* A class that responses for damage and armor 
of unit, weapon, shield and armor */
class Battles
{
public:
	explicit Battles(int value);
	Battles(const Battles&) = default;
	Battles(Battles&&) = default;
	Battles& operator=(const Battles&) = default;
	Battles& operator=(Battles&&) = default;
	Battles() = default;
public:
	void changeValue(int value);
	operator int()const;
protected:
	int m_value;
};
#endif