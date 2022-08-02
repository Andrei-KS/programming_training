#ifndef __SALARIEDCLASSIFICATION_H__
#define __SALARIEDCLASSIFICATION_H__

#include "PayrollDOmain/PaymentClassification.h"

class SalariedClassification : public PaymentClassification
{
public:
	virtual ~SalariedClassification();
	SalariedClassification(double salary);
	double GetSalary() { return itsSalary; }
	virtual double CalculatePay(const Paycheck& pc) const;
	virtual void AddItem(Date& date, double value, PaymentClassification* thisObject) override;
private:
	double itsSalary;
};

#endif // !__SALARIEDCLASSIFICATION_H__
