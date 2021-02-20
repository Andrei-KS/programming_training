

#include "../../header/Transaction/ChangeNameTransaction.h"

ChangeNameTransaction::~ChangeNameTransaction()
{
}

ChangeNameTransaction::ChangeNameTransaction(int empId, std::string name)
	: ChangeEmployeeTransaction(empId)
	, itsName(name)
{
}

void ChangeNameTransaction::Change(Employee& e)
{
	e.SetName(itsName);
}