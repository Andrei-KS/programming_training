

#include "../../header/Transaction/AddEmployeeTransaction.h"
#include "../../header/PaymentMethod/HoldMethod.h"
#include "../../header/Employee.h"
#include "../../header/Database/PayrollDatabase.h"

class PaymentMethod;
class PaymentSchedule;
class PaymentClassification;

extern PayrollDatabase GpayrollDatabase;

AddEmployeeTransaction::~AddEmployeeTransaction()
{
}

AddEmployeeTransaction::
AddEmployeeTransaction(int empId, std::string name, std::string address)
	: ItsEmpId(empId)
	, itsName(name)
	, itsAddress(address)
{
}

void AddEmployeeTransaction::Execute()
{
	PaymentClassification* pc = GetClassification();
	PaymentSchedule* ps = GetSchedule();
	PaymentMethod* pm = new HoldMethod();
	Employee* e = new Employee(ItsEmpId, itsName, itsAddress);
	e->SetClassification(pc);
	e->SetSchedule(ps);
	e->SetMethod(pm);
	GpayrollDatabase.AddEmployee(ItsEmpId, e);
}