

#include "ChangeSalariedTransaction.h"
#include "PayrollFactory/PayrollFactory.h"

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
	return PayrollFactory::CurrentPayrollFactory->makeSalariedClassification(itsSalary);
}

PaymentSchedule* ChangeSalariedTransaction::GetSchedule() const
{
	return PayrollFactory::CurrentPayrollFactory->makeMonthlySchedule();
}
