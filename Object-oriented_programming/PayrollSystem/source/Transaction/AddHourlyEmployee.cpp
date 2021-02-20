

#include "../../header/Transaction/AddHourlyEmployee.h"
#include "../../header/PaymentClassification/HourlyClassification.h"
#include "../../header/PaymentSchedule/WeeklySchedule.h"

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

