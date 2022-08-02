

#include "ChangeUnaffiliatedTransaction.h"
#include "PayrollDomain/Affiliation.h"
#include "PayrollDatabase/PayrollDatabase.h"
#include "PayrollFactory/PayrollFactory.h"

extern PayrollDatabase GpayrollDatabase;

ChangeUnaffiliatedTransaction::~ChangeUnaffiliatedTransaction()
{
}

ChangeUnaffiliatedTransaction::ChangeUnaffiliatedTransaction(int empId)
	: ChangeAffiliationTransaction(empId)
{
}

Affiliation* ChangeUnaffiliatedTransaction::GetAffiliation() const
{
	return PayrollFactory::CurrentPayrollFactory->makeNoAffiliation();
}

void ChangeUnaffiliatedTransaction::RecordMembership(Employee* e)
{
	Affiliation* af = e->GetAffiliation();
	int memberId = af->GetMemberId();
	if (memberId != -1)
	{
		GpayrollDatabase.RemoveUnionMember(memberId);
	}
}
