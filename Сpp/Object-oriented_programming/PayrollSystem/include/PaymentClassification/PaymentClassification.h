#ifndef __PAYMENTCLASSIFICATION_H__
#define __PAYMENTCLASSIFICATION_H__

class Paycheck;

class PaymentClassification
{
public:
	virtual ~PaymentClassification();
	PaymentClassification();
	virtual double CalculatePay(const Paycheck& pc) const = 0;
};

#endif // !__PAYMENTCLASSIFICATION_H__