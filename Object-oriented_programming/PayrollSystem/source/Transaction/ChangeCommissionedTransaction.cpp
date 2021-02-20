

#include "../../header/Transaction/ChangeCommissionedTransaction.h"
#include "../../header/PaymentClassification/CommissionedClassification.h"
#include "../../header/PaymentSchedule/BiweeklySchedule.h"

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
