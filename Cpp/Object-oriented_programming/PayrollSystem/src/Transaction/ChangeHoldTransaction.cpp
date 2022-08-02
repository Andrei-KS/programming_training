

#include "Transaction/ChangeHoldTransaction.h"
#include "PaymentMethod/HoldMethod.h"

ChangeHoldTransaction::~ChangeHoldTransaction()
{
}

ChangeHoldTransaction::ChangeHoldTransaction(int empId)
	: ChangeMethodTransaction(empId)
{
}

PaymentMethod* ChangeHoldTransaction::GetMethod() const
{
	return new HoldMethod();
}
