

#include "../../header/PaymentClassification/SalariedClassification.h"

SalariedClassification::~SalariedClassification()
{
}

SalariedClassification::SalariedClassification(double salary)
	: itsSalary(salary)
{
}

double SalariedClassification::CalculatePay(const Paycheck& pc) const
{
	return itsSalary;
}
