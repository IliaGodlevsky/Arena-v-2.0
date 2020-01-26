#ifndef MP_REDUCE_ELEM_H_
#define MP_REDUCE_ELEM_H_

#include "../../Globals/Globals.h"

class MpReduceElem
{
public:
	MpReduceElem(int mpReduce);
	void effectUnit(Unit& unit);
	operator int()const;
private:
	int m_mpReduce = 0;
};

#endif
