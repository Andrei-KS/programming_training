

#include "Transaction/ChangeCommissionedTransaction.h"
#include "PaymentClassification/CommissionedClassification.h"
#include "PaymentSchedule/BiweeklySchedule.h"

ChangeCommissionedTransaction::~ChangeCommissionedTransaction()
{
}

ChangeCommissionedTransaction::ChangeCommissionedTransaction(int empId, double salary, double commissionRate)
	: ChangeClassificationTransaction(empId)
	, itsSalary(salary)
	, itsCommissionRate(commissionRate)
{
}

PaymentClassification* ChangeCommissionedTransaction::GetClassification() const
{
	return new CommissionedClassification( itsSalary, itsCommissionRate);
}

PaymentSchedule* ChangeCommissionedTransaction::GetSchedule() const
{
	return new BiweeklySchedule();
}
