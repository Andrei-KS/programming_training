#ifndef __SERVICECHARGETRANSACTION_H__
#define __SERVICECHARGETRANSACTION_H__

#include "Transaction.h"

class ServiceChargeTransaction : public Transaction
{
public:
	virtual ~ServiceChargeTransaction();
	ServiceChargeTransaction(int memberId, long date, double charge);
	virtual void Execute() override;

private:
	int itsMemberId;
	long itsDate;
	double itsCharge;

};

#endif // !__SERVICECHARGETRANSACTION_H__
