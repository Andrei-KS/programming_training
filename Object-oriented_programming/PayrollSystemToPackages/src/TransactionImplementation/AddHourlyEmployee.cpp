

#include "AddHourlyEmployee.h"
#include "PayrollFactory/PayrollFactory.h"

AddHourlyEmployee::~AddHourlyEmployee()
{
}

AddHourlyEmployee::
AddHourlyEmployee(int empId, std::string name, std::string address, double hourlyRate)
	: AddEmployeeTransaction(empId,name,address)
	, itsHourlyRate(hourlyRate)
{
}

PaymentClassification* AddHourlyEmployee::GetClassification() const
{
	return PayrollFactory::CurrentPayrollFactory->makeHourlyClassification(itsHourlyRate);
}

PaymentSchedule* AddHourlyEmployee::GetSchedule() const
{
	return PayrollFactory::CurrentPayrollFactory->makeWeeklySchedule();
}

PaymentMethod* AddHourlyEmployee::GetMethod() const
{
	return PayrollFactory::CurrentPayrollFactory->makeHoldMethod();
}
