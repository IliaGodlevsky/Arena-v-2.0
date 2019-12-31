#ifndef MAGIC_H_
#define MAGIC_H_

#include <type_traits>

#include "../Globals/Globals.h"
#include "../Timer/Timer.h"

// WARNING: item = unique_ptr<T>, type = T*
#define DYNAMIC(type, item) (dynamic_cast<type>(item.get()))

template <typename T, typename D>
inline bool canCast(const std::unique_ptr<D>& item)
{
	if (NULLPTR == item)
		return NO;
	T temp = DYNAMIC(T, item);
	return NULLPTR != temp;
}

class Magic
{
public:
	Magic(std::string name,
		int manaCost, const Timer& timer);
	virtual ~Magic();
public:
	virtual void effectUnit(Unit& unit) = 0;
	virtual void uneffectUnit(Unit& unit)const = 0;
	virtual MagicPtr clone()const = 0; // Prototype
	virtual bool isBuff()const = 0;
	virtual void showFullInfo()const = 0;
	virtual void showShortInfo()const final;
public:
	virtual bool isExpired(int round)const final;
	virtual void setStartTime(int round);
	virtual const std::string& getName()const final;
	virtual bool isEnoughMana(int currentMana)const final;
	virtual int getCost()const final;
	virtual int getDuration()const final;
	virtual bool isEqual(const MagicPtr& magic)const;
protected:
	virtual bool hasEqualParametres(const MagicPtr& magic)const = 0;
	virtual void showData()const = 0;
	virtual void putOn(Unit& unit)const = 0;
protected:
	std::string m_name;
	int m_manaCost;
	Timer m_timer;
};

#endif