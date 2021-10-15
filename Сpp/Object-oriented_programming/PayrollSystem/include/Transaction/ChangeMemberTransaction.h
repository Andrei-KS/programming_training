#ifndef __CHANGEMEMBERTRANSACTION_H__
#define __CHANGEMEMBERTRANSACTION_H__

#include "ChangeAffiliationTransaction.h"

class ChangeMemberTransaction : public ChangeAffiliationTransaction
{
public:
	virtual ~ChangeMemberTransaction();
	ChangeMemberTransaction(int empId, int memberId, double dues);
	virtual Affiliation* GetAffiliation() const override;
	virtual void RecordMembership(Employee* e) override;

private:
	int itsMemberId;
	double itsDues;

};

#endif // !__CHANGEMEMBERTRANSACTION_H__