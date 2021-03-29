#ifndef __PAYMENTCLASSIFICATION_H__
#define __PAYMENTCLASSIFICATION_H__

class Paycheck;
class Date;

class PaymentClassification
{
public:
	virtual ~PaymentClassification();
	PaymentClassification();
	virtual double CalculatePay(const Paycheck& pc) const = 0;
	virtual void AddItem(Date& date, double value, PaymentClassification* thisObject) = 0;
};

#endif // !__PAYMENTCLASSIFICATION_H__