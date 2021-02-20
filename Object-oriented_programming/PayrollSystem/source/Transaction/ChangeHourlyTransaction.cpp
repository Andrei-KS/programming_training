

#include "../../header/Transaction/ChangeHourlyTransaction.h"
#include "../../header/PaymentSchedule/WeeklySchedule.h"
#include "../../header/PaymentClassification/HourlyClassification.h"

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
	return new HourlyClassification(itsHourlyRate);
}

PaymentSchedule* ChangeHourlyTransaction::GetSchedule() const
{
	return new WeeklySchedule();
}
