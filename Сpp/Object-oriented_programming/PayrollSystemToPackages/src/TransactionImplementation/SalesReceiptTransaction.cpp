

#include "SalesReceiptTransaction.h"
#include "PayrollDomain/Employee.h"
#include "PayrollDatabase/PayrollDatabase.h"
#include "PayrollDomain/PaymentClassification.h"

extern PayrollDatabase GpayrollDatabase;

SalesReceiptTransaction::~SalesReceiptTransaction()
{
}

SalesReceiptTransaction::SalesReceiptTransaction(const Date& date, double amount, int empId)
	: itsDate(date)
	, itsAmount(amount)
	, itsEmpId(empId)
{
}

void SalesReceiptTransaction::Execute()
{
	Employee* e = GpayrollDatabase.GetEmployee(itsEmpId);
	if (e)
	{
		PaymentClassification* pc = e->GetClassification();
		pc->AddItem(itsDate, itsAmount, pc);
	}
	else
	{
		throw("No such employee.");
	}
}
