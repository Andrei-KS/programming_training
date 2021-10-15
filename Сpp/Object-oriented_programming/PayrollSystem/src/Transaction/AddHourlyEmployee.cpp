

#include "Transaction/AddHourlyEmployee.h"
#include "PaymentClassification/HourlyClassification.h"
#include "PaymentSchedule/WeeklySchedule.h"

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
	return new HourlyClassification(itsHourlyRate);
}

PaymentSchedule* AddHourlyEmployee::GetSchedule() const
{
	return new WeeklySchedule();
}

