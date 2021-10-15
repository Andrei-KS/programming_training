

#include "SalariedClassification.h"

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

void SalariedClassification::AddItem(Date& date, double value, PaymentClassification* thisObject)
{
	throw("Tried to add Item to Salaried employee");
}
