

#include "ChangeMailTransaction.h"
#include "PayrollFactory/PayrollFactory.h"

ChangeMailTransaction::~ChangeMailTransaction()
{
}

ChangeMailTransaction::ChangeMailTransaction(int empId, std::string address)
	: ChangeMethodTransaction(empId)
	, itsAddress(address)
{
}

PaymentMethod* ChangeMailTransaction::GetMethod() const
{
	return PayrollFactory::CurrentPayrollFactory->makeMailMethod(itsAddress);
}
