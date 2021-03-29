

#include "ChangeDirectTransaction.h"
#include "PayrollFactory/PayrollFactory.h"

ChangeDirectTransaction::~ChangeDirectTransaction()
{
}

ChangeDirectTransaction::ChangeDirectTransaction(int empId, std::string bank, std::string account)
	: ChangeMethodTransaction(empId)
	, itsBank(bank)
	, itsAccount(account)
{
}

PaymentMethod* ChangeDirectTransaction::GetMethod() const
{
	return PayrollFactory::CurrentPayrollFactory->makeDirectMethod(itsBank, itsAccount);
}
