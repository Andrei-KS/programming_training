

#include "Transaction/ChangeMethodTransaction.h"

ChangeMethodTransaction::~ChangeMethodTransaction()
{
}

ChangeMethodTransaction::ChangeMethodTransaction(int empId)
	: ChangeEmployeeTransaction(empId)
{
}

void ChangeMethodTransaction::Change(Employee& e)
{
	e.SetMethod(GetMethod());
}
