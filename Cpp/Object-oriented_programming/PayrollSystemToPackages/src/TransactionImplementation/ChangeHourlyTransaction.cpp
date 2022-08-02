

#include "ChangeHourlyTransaction.h"
#include "PayrollFactory/PayrollFactory.h"

ChangeHourlyTransaction::~ChangeHourlyTransaction()
{
}

ChangeHourlyTransaction::ChangeHourlyTransaction(int empId, double hourlyRate)
	: ChangeClassificationTransaction(empId)
	, itsHourlyRate(hourlyRate)
{
}

PaymentClassification* ChangeHourlyTransaction::GetClassification() const
{
	return PayrollFactory::CurrentPayrollFactory->makeHourlyClassification(itsHourlyRate);
}

PaymentSchedule* ChangeHourlyTransaction::GetSchedule() const
{
	return PayrollFactory::CurrentPayrollFactory->makeWeeklySchedule();
}
