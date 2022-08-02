

#include "ChangeHoldTransaction.h"
#include "PayrollFactory/PayrollFactory.h"

ChangeHoldTransaction::~ChangeHoldTransaction()
{
}

ChangeHoldTransaction::ChangeHoldTransaction(int empId)
	: ChangeMethodTransaction(empId)
{
}

PaymentMethod* ChangeHoldTransaction::GetMethod() const
{
	return PayrollFactory::CurrentPayrollFactory->makeHoldMethod();
}
