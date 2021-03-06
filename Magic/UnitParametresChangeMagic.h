#ifndef PARAM_CHANGE_MAGIC_H_
#define PARAM_CHANGE_MAGIC_H_

#include "ManaFreeUnitParametresChangeMagic.h"
#include "../Interface/Interface.h"
#include "Elements/ParamChangeElem.h"

/* A base class for all magic, that comes to magic book*/
class UnitParametresChangeMagic : public ManaFreeUnitParametresChangeMagic, 
	public IBuff, public IManaCost
{
public:
	virtual bool isEqual(const MagicPtr& magic)const override;
	virtual void showFullInfo()const override;
	virtual void showShortInfo()const override;
	virtual ~UnitParametresChangeMagic() = default;
	UnitParametresChangeMagic(std::string name, int manaCost,
		Time time, const ElementsInitializerList& holder);
	UnitParametresChangeMagic(std::string name, int manaCost,
		Time time, const ElementHolder& holder);
};
#endif
