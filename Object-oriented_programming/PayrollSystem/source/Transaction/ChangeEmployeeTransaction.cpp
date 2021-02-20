

#include "../../header/Transaction/ChangeEmployeeTransaction.h"
#include "../../header/Employee.h"
#include "../../header/Database/PayrollDatabase.h"

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
