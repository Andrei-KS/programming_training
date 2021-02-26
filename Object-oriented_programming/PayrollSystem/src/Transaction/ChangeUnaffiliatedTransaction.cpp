

#include "Transaction/ChangeUnaffiliatedTransaction.h"
#include "Affiliation/NoAffiliation.h"
#include "Affiliation/UnionAffiliation.h"
#include "Database/PayrollDatabase.h"

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
	return new NoAffiliation();
}

void ChangeUnaffiliatedTransaction::RecordMembership(Employee* e)
{
	Affiliation* af = e->GetAffiliation();
	if (UnionAffiliation* uf = dynamic_cast<UnionAffiliation*>(af))
	{
		int memberId = uf->GetMemberId();
		GpayrollDatabase.RemoveUnionMember(memberId);
	}
}
