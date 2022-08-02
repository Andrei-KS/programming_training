

#include "Transaction/ChangeSalariedTransaction.h"
#include "PaymentClassification/SalariedClassification.h"
#include "PaymentSchedule/MonthlySchedule.h"

ChangeSalariedTransaction::~ChangeSalariedTransaction()
{
}

ChangeSalariedTransaction::ChangeSalariedTransaction(int empId, double salary)
	: ChangeClassificationTransaction(empId)
	, itsSalary(salary)
{
}

PaymentClassification* ChangeSalariedTransaction::GetClassification() const
{
	return new SalariedClassification(itsSalary);
}

PaymentSchedule* ChangeSalariedTransaction::GetSchedule() const
{
	return new MonthlySchedule();
}
