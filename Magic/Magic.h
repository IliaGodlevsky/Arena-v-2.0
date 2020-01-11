#ifndef MAGIC_H_
#define MAGIC_H_

#include <type_traits>

#include "../Globals/Globals.h"

// WARNING: item = unique_ptr<T>, type = T*
#define DYNAMIC(type, item) (dynamic_cast<type>(item.get()))

template <typename T, typename D>
inline bool canCast(const std::unique_ptr<D>& item)
{
	if (nullptr == item)
		return false;
	T temp = DYNAMIC(T, item);
	return nullptr != temp;
}

class Magic
{
public:
	Magic(std::string name);
	virtual ~Magic() = default;
public:
	virtual void effectUnit(Unit& unit) = 0;
	virtual MagicPtr clone()const = 0; // Prototype
	virtual bool isEqual(const MagicPtr& magic)const = 0;
	virtual void showFullInfo()const = 0;
	virtual void showShortInfo()const = 0;
	const std::string& getName()const;
protected:
	std::string m_name;
};

#endif