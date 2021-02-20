

#include "../../header/Transaction/ServiceChargeTransaction.h"
#include "../../header/Employee.h"
#include "../../header/Affiliation/ServiceCharge.h"
#include "../../header/Database/PayrollDatabase.h"
#include "../../header/Affiliation/UnionAffiliation.h"

extern PayrollDatabase GpayrollDatabase;

ServiceChargeTransaction::~ServiceChargeTransaction()
{
}

ServiceChargeTransaction::
ServiceChargeTransaction(int memberId, long date, double charge)
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
		if (UnionAffiliation* uaf = dynamic_cast<UnionAffiliation*>(af))
		{
			uaf->AddServiceCharge(new ServiceCharge(itsDate, itsCharge));
		}
		else
		{
			throw("Tried to add servicecharge to non-unionaffiliation employee");
		}
	}
	else
	{
		throw("No such employee.");
	}
	
}
