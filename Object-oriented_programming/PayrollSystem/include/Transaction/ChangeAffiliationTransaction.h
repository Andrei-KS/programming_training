#ifndef __CHANGEAFFILIATIONTRANSACTION_H__
#define __CHANGEAFFILIATIONTRANSACTION_H__

#include "ChangeEmployeeTransaction.h"

class ChangeAffiliationTransaction : public ChangeEmployeeTransaction
{
public:
	virtual ~ChangeAffiliationTransaction();
	ChangeAffiliationTransaction(int empId);
	virtual Affiliation* GetAffiliation() const = 0;
	virtual void RecordMembership(Employee* e) = 0;
	virtual void Change(Employee& e) override;
};

#endif // !__CHANGEAFFILIATIONTRANSACTION_H__