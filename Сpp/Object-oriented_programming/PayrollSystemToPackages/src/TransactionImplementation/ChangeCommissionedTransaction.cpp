

#include "ChangeCommissionedTransaction.h"
#include "PayrollFactory/PayrollFactory.h"

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
	return PayrollFactory::CurrentPayrollFactory->makeCommissionedClassification( itsSalary, itsCommissionRate);
}

PaymentSchedule* ChangeCommissionedTransaction::GetSchedule() const
{
	return PayrollFactory::CurrentPayrollFactory->makeBiweeklySchedule();
}
