

#include "AddCommissionedEmployee.h"
#include "PayrollFactory/PayrollFactory.h"

AddCommissionedEmployee::~AddCommissionedEmployee()
{
}

AddCommissionedEmployee::
AddCommissionedEmployee(int empId, std::string name, std::string address, double salary, double commissionRate)
	: AddEmployeeTransaction(empId,name,address)
	, itsSalary(salary)
	, itsCommissionRate(commissionRate)
{
}

PaymentClassification* AddCommissionedEmployee::GetClassification() const
{
	return PayrollFactory::CurrentPayrollFactory->makeCommissionedClassification(itsSalary, itsCommissionRate);
}

PaymentSchedule* AddCommissionedEmployee::GetSchedule() const
{
	return PayrollFactory::CurrentPayrollFactory->makeBiweeklySchedule();
}

PaymentMethod* AddCommissionedEmployee::GetMethod() const
{
	return PayrollFactory::CurrentPayrollFactory->makeHoldMethod();
}
