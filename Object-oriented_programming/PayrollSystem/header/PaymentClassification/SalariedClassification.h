#ifndef __SALARIEDCLASSIFICATION_H__
#define __SALARIEDCLASSIFICATION_H__

#include "PaymentClassification.h"

class SalariedClassification : public PaymentClassification
{
public:
	virtual ~SalariedClassification();
	SalariedClassification(double salary);
	double GetSalary() { return itsSalary; }

private:
	double itsSalary;
};

#endif // !__SALARIEDCLASSIFICATION_H__
