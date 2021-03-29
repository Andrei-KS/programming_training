

#include "ChangeEmployeeTransaction.h"
#include "PayrollDomain/Employee.h"
#include "PayrollDatabase/PayrollDatabase.h"

extern PayrollDatabase GpayrollDatabase;

ChangeEmployeeTransaction::~ChangeEmployeeTransaction()
{
}

ChangeEmployeeTransaction::ChangeEmployeeTransaction(int empId)
	: itsEmpId(empId)
{
}

void ChangeEmployeeTransaction::Execute()
{
	Employee* e = GpayrollDatabase.GetEmployee(itsEmpId);
	if (e != nullptr)
	{
		Change(*e);
	}
}
