

#include "Transaction/SalesReceiptTransaction.h"
#include "Employee.h"
#include "Database/PayrollDatabase.h"
#include "PaymentClassification/CommissionedClassification.h"

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
		if (CommissionedClassification* cc = dynamic_cast<CommissionedClassification*>(pc))
		{
			cc->AddSalesReceipt(itsDate, itsAmount);
		}
		else
		{
			throw("Tried to add salesreceipt to non-commissioned employee");
		}
	}
	else
	{
		throw("No such employee.");
	}
}
