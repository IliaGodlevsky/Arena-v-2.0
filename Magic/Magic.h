#ifndef MAGIC_H_
#define MAGIC_H_

#include "../Globals/Globals.h"

template <typename ClassPointer, typename SmartPointer>
constexpr inline auto dCast(const SmartPointer& item)
{
	return dynamic_cast<ClassPointer>(item.get());
}

template <typename ClassPointer, typename SmartPointer>
constexpr inline auto canCast(const SmartPointer& pointer)
{
	return nullptr != dCast<ClassPointer>(pointer);
}

template <class DerivedClassPointer, class BaseClass>
constexpr inline bool isEqual(const MagicPtr& magic)
{
	return canCast<DerivedClassPointer>(magic)
		&& BaseClass::isEqual(magic);
}

// a base interface for all magic classes in the game
class Magic
{
public:
	Magic(std::string name);
	virtual ~Magic() = default;
	virtual void effectUnit(Unit& unit) = 0;
	virtual MagicPtr clone()const = 0; // Prototype
	virtual bool isEqual(const MagicPtr& magic)const = 0;
	const std::string& getName()const;
	virtual void showFullInfo()const = 0;
	virtual void showShortInfo()const = 0;
protected:
	std::string m_name;
};

#endif