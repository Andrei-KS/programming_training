#ifndef __HOLDMETHOD_H__
#define __HOLDMETHOD_H__

#include "PayrollDomain/PaymentMethod.h"

class HoldMethod : public PaymentMethod
{
public:
	virtual ~HoldMethod();
	HoldMethod();
	virtual void Pay(Paycheck& pc) const override;
};

#endif // !__HOLDMETHOD_H__