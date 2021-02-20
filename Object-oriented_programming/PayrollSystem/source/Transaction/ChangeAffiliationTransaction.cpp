

#include "../../header/Transaction/ChangeAffiliationTransaction.h"

ChangeAffiliationTransaction::~ChangeAffiliationTransaction()
{
}

ChangeAffiliationTransaction::ChangeAffiliationTransaction(int empId)
	: ChangeEmployeeTransaction(empId)
{
}

void ChangeAffiliationTransaction::Change(Employee& e)
{
	RecordMembership(&e);
	e.SetAffiliation(GetAffiliation());
}
