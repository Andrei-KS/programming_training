#ifndef __SALARIEDCLASSIFICATION_H__
#define __SALARIEDCLASSIFICATION_H__

#include "PaymentClassification.h"

class SalariedClassification : public PaymentClassification
{
public:
	virtual ~SalariedClassification();
	SalariedClassification(double salary);
	double GetSalary() { return itsSalary; }
	virtual double CalculatePay(const Paycheck& pc) const;

private:
	double itsSalary;
};

#endif // !__SALARIEDCLASSIFICATION_H__
