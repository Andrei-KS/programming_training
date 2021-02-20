

#include "../../header/Transaction/ChangeAddressTransaction.h"

ChangeAddressTransaction::~ChangeAddressTransaction()
{
}

ChangeAddressTransaction::ChangeAddressTransaction(int empId, std::string address)
	: ChangeEmployeeTransaction(empId)
	, itsAddress(address)
{
}

void ChangeAddressTransaction::Change(Employee& e)
{
	e.SetAddress(itsAddress);
}
