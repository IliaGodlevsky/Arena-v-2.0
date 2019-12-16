#include "Silence.h"
#include "Unit.h"

Silence::Silence(std::string name, int mana_cost,
	int duration)
	: Magic(name, mana_cost, duration)
{

}

void Silence::effectUnit(Unit& unit)
{
	putOn(unit);
	Magic::effectUnit(unit);
	unit.recieveNewState(std::shared_ptr<UnitState>(new MutedState(m_durationmeter)));
}

void Silence::uneffectUnit(Unit& unit)const
{
	return;
}

MagicPtr Silence::clone()const
{
	return MagicPtr(new Silence(m_name, m_manaCost, m_durationmeter));
}

bool Silence::isBuff()const
{
	return false;
}

bool Silence::hasEqualParametres(const MagicPtr& magic)const
{
	if (nullptr == magic)
		return false;
	Silence* temp = DYNAMIC(Silence*, magic);
	if (nullptr == temp)
		return false;
	return Magic::isEqual(magic);
}

bool Silence::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic) &&
		hasEqualParametres(magic);
}

void Silence::putOn(Unit& unit)const
{
	return;
}

void Silence::showFullInfo()const
{
	Magic::showData();
	showData();
}

void Silence::showData()const
{
	std::cout << "Enemy can't cast spells\n";
}