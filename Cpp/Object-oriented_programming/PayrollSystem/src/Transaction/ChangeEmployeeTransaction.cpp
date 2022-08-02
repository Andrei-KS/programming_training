

#include "Transaction/ChangeEmployeeTransaction.h"
#include "Employee.h"
#include "Database/PayrollDatabase.h"

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
