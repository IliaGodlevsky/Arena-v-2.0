#ifndef HP_REDUCE_H_
#define HP_REDUCE_H_

#include "../../Globals/Globals.h"

class HpReduceElem
{
public:
	HpReduceElem(int hpReduce);
	void effectUnit(Unit& unit);
	~HpReduceElem() = default;
	void showFullInfo()const;
	operator int()const;
protected:
	int m_hpReduce = 0;
};
#endif
