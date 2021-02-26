#ifndef __CHANGEUNAFFILIATEDTRANSACTION_H__
#define __CHANGEUNAFFILIATEDTRANSACTION_H__

#include "ChangeAffiliationTransaction.h"

class ChangeUnaffiliatedTransaction : public ChangeAffiliationTransaction
{
public:
	virtual ~ChangeUnaffiliatedTransaction();
	ChangeUnaffiliatedTransaction(int empId);
	virtual Affiliation* GetAffiliation() const override;
	virtual void RecordMembership(Employee* e) override;

};

#endif // !__CHANGEUNAFFILIATEDTRANSACTION_H__
