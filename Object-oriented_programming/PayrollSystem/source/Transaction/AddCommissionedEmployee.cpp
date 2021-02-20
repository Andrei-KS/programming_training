

#include "../../header/Transaction/AddCommissionedEmployee.h"
#include "../../header/PaymentClassification/CommissionedClassification.h"
#include "../../header/PaymentSchedule/BiweeklySchedule.h"

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
	return new CommissionedClassification(itsSalary, itsCommissionRate);
}

PaymentSchedule* AddCommissionedEmployee::GetSchedule() const
{
	return new BiweeklySchedule();
}

