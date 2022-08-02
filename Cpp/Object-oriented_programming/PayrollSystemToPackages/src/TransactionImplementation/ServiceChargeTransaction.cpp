

#include "ServiceChargeTransaction.h"
#include "PayrollDomain/Employee.h"
#include "PayrollDatabase/PayrollDatabase.h"
#include "PayrollDomain/Affiliation.h"

extern PayrollDatabase GpayrollDatabase;

ServiceChargeTransaction::~ServiceChargeTransaction()
{
}

ServiceChargeTransaction::
ServiceChargeTransaction(int memberId, const Date& date, double charge)
	: itsMemberId(memberId)
	, itsDate(date)
	, itsCharge(charge)
{
}

void ServiceChargeTransaction::Execute()
{
	Employee* e = GpayrollDatabase.GetUnionMember(itsMemberId);
	if (e)
	{
		Affiliation* af = e->GetAffiliation();
		af->AddItem(itsDate, itsCharge, af);
	}
	else
	{
		throw("No such employee.");
	}
	
}
