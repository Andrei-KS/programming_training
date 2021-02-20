#ifndef __HOLDMETHOD_H__
#define __HOLDMETHOD_H__

#include "PaymentMethod.h"

class HoldMethod : public PaymentMethod
{
public:
	virtual ~HoldMethod();
	HoldMethod();
};

#endif // !__HOLDMETHOD_H__