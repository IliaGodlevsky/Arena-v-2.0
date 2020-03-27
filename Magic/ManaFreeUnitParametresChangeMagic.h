#ifndef FREE_PARAM_CHANGE_MAGIC_H_
#define FREE_PARAM_CHANGE_MAGIC_H_

#include "Magic.h"
#include "../Interface/Interface.h"
#include "Elements/ParamChangeElem.h"
#include "../Expiring/Expiring.h"
#include "ElementHolder.h"

/* A base for all magic, that can be casted by weapon*/
class ManaFreeUnitParametresChangeMagic : public Magic, 
	public IUneffect, public IDispelable, public Expiring
{
public:	
	virtual void effectUnit(Unit& unit);
	virtual void uneffectUnit(Unit& unit);
	bool isEqual(const MagicPtr& magic)const override;
	void showFullInfo()const override;
	void showShortInfo()const override;
	virtual ~ManaFreeUnitParametresChangeMagic() = default;
	ManaFreeUnitParametresChangeMagic(std::string name, Time time,
		const ElementsInitializerList& holder);
	ManaFreeUnitParametresChangeMagic(std::string name, Time time,
		const ElementHolder& holder);
protected:
	ElementHolder m_elemHolder;
};
#endif
