

#include "Transaction/ChangeDirectTransaction.h"
#include "PaymentMethod/DirectMethod.h"

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
	return new DirectMethod(itsBank, itsAccount);
}
