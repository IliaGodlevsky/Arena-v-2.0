#ifndef BATTLES_H_
#define BATTLES_H_

/* A class that responses for damage or armor */
class Battles
{
public:
	explicit Battles(int value);
	Battles(const Battles&) = default;
	Battles(Battles&&) = default;
	Battles& operator=(const Battles&) = default;
	Battles& operator=(Battles&&) = default;
	Battles() = default;
	void changeValue(int value);
	void changeAdditaionalValue(int additionalValue);	
	void showShortInfo(const char* valueType)const;
	operator int()const;
protected:
	void setBattlesColor()const;
	int m_value = 0;
	int m_additionalValue = 0;
};
#endif