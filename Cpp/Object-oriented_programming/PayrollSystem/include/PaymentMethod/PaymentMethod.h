#ifndef __PAYMENTMETHOD_H__
#define __PAYMENTMETHOD_H__

class Paycheck;

class PaymentMethod 
{
public:
	virtual ~PaymentMethod();
	PaymentMethod();
	virtual void Pay(Paycheck& pc) const = 0;
};

#endif // !__PAYMENTMETHOD_H__