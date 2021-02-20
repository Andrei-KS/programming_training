

#include "../../header/Transaction/ChangeSalariedTransaction.h"
#include "../../header/PaymentClassification/SalariedClassification.h"
#include "../../header/PaymentSchedule/MonthlySchedule.h"

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
