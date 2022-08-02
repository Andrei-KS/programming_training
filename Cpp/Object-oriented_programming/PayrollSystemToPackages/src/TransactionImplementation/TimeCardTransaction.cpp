

#include "TimeCardTransaction.h"
#include "PayrollDomain/Employee.h"
#include "PayrollDatabase/PayrollDatabase.h"
#include "PayrollDomain/PaymentClassification.h"

extern PayrollDatabase GpayrollDatabase;

TimeCardTransaction::~TimeCardTransaction()
{
}

TimeCardTransaction::TimeCardTransaction(const Date& date, double hours, int empId)
	: itsDate(date)
	, itsHours(hours)
	, itsEmpId(empId)
{
}

void TimeCardTransaction::Execute()
{
	Employee* e = GpayrollDatabase.GetEmployee(itsEmpId);
	if (e)
	{
		PaymentClassification* pc = e->GetClassification();
		pc->AddItem(itsDate, itsHours, pc);
	}
	else
	{
		throw("No such employee.");
	}
}
