

#include "../../header/Transaction/SalesReceiptTransaction.h"
#include "../../header/Employee.h"
#include "../../header/Database/PayrollDatabase.h"
#include "../../header/PaymentClassification/CommissionedClassification.h"
#include "../../header/PaymentClassification/SalesReceipt.h"

extern PayrollDatabase GpayrollDatabase;

SalesReceiptTransaction::~SalesReceiptTransaction()
{
}

SalesReceiptTransaction::SalesReceiptTransaction(long date, double amount, int empId)
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
			cc->AddSalesReceipt(new SalesReceipt(itsDate, itsAmount));
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
