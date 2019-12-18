#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"

#include "WeaponMagic.h"

WeaponMagic::WeaponMagic(std::string name, int duration, int propability)
	: Magic(name, ZERO_MANA_COST, duration), m_propability(propability)
{

}

WeaponMagic::~WeaponMagic() {}

bool WeaponMagic::isCastChance()const
{
	return PosibilityCounter(m_propability);
}

void WeaponMagic::showFullInfo()const
{
	showData();
}

void WeaponMagic::showData()const
{
	std::cout << "Name: " << m_name << std::endl;
	std::cout << "Duration: " << m_timer << std::endl;
	std::cout << "Posibility: " << m_propability << std::endl;
}

bool WeaponMagic::hasEqualParametres(const MagicPtr& magic)const
{
	WeaponMagic* temp = DYNAMIC(WeaponMagic*, magic);
	if (nullptr == temp)
		return false;
	return m_propability == temp->m_propability;
}

bool WeaponMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}
