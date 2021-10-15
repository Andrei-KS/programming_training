

#include "ChangeMemberTransaction.h"
#include "PayrollFactory/PayrollFactory.h"
#include "PayrollDatabase/PayrollDatabase.h"

extern PayrollDatabase GpayrollDatabase;

ChangeMemberTransaction::~ChangeMemberTransaction()
{
}

ChangeMemberTransaction::ChangeMemberTransaction(int empId, int memberId, double dues)
	: ChangeAffiliationTransaction (empId)
	, itsMemberId(memberId)
	, itsDues(dues)
{
}

Affiliation* ChangeMemberTransaction::GetAffiliation() const
{
	return PayrollFactory::CurrentPayrollFactory->makeAffiliation(itsMemberId,itsDues);
}

void ChangeMemberTransaction::RecordMembership(Employee* e)
{
	GpayrollDatabase.AddUnionMember(itsMemberId, e);
}