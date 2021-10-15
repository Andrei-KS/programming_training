#ifndef __SERVICECHARGETRANSACTION_H__
#define __SERVICECHARGETRANSACTION_H__

#include "Transaction.h"
#include "../Date.h"

class ServiceChargeTransaction : public Transaction
{
public:
	virtual ~ServiceChargeTransaction();
	ServiceChargeTransaction(int memberId, const Date& date, double charge);
	virtual void Execute() override;

private:
	int itsMemberId;
	Date itsDate;
	double itsCharge;

};

#endif // !__SERVICECHARGETRANSACTION_H__
