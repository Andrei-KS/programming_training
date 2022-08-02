

#include "AddSalariedEmployee.h"
#include "PayrollFactory/PayrollFactory.h"

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
	return PayrollFactory::CurrentPayrollFactory->makeSalariedClassification(itsSalary);
}

PaymentSchedule* AddSalariedEmployee::GetSchedule() const
{
	return PayrollFactory::CurrentPayrollFactory->makeMonthlySchedule();
}

PaymentMethod* AddSalariedEmployee::GetMethod() const
{
	return PayrollFactory::CurrentPayrollFactory->makeHoldMethod();
}




