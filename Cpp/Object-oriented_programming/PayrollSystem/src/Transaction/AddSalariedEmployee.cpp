

#include "Transaction/AddSalariedEmployee.h"
#include "PaymentClassification/SalariedClassification.h"
#include "PaymentSchedule/MonthlySchedule.h"

AddSalariedEmployee::~AddSalariedEmployee()
{
}

AddSalariedEmployee::
AddSalariedEmployee(int empId, std::string name, std::string address, double salary)
	: AddEmployeeTransaction(empId,name,address)
	, itsSalary(salary)
{
}

PaymentClassification* AddSalariedEmployee::GetClassification() const
{
	return new SalariedClassification(itsSalary);
}

PaymentSchedule* AddSalariedEmployee::GetSchedule() const
{
	return new MonthlySchedule();
}




