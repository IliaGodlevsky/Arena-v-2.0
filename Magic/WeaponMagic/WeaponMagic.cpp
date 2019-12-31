#include "../../Unit/Unit.h"
#include "../../UnitState/UnitState.h"

#include "WeaponMagic.h"

WeaponMagic::WeaponMagic(std::string name, const Timer& timer, int propability)
	: Magic(name, ZERO_MANA_COST, timer), m_propability(propability)
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
	std::cout << "Duration: " << m_timer.getDuration() << std::endl;
	std::cout << "Posibility: " << m_propability << std::endl;
}

bool WeaponMagic::hasEqualParametres(const MagicPtr& magic)const
{
	if (!canCast<WeaponMagic*>(magic))
		return NO;
	WeaponMagic* temp = DYNAMIC(WeaponMagic*, magic);
	return m_propability == temp->m_propability;
}

bool WeaponMagic::isEqual(const MagicPtr& magic)const
{
	return Magic::isEqual(magic)
		&& hasEqualParametres(magic);
}
