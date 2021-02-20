#ifndef __TIMECARDTRANSACTION_H__
#define __TIMECARDTRANSACTION_H__

#include "Transaction.h"

class TimeCardTransaction : public Transaction
{
public:
	virtual ~TimeCardTransaction();
	TimeCardTransaction(long date, double hours, int empId);
	virtual void Execute() override;

private:
	int itsEmpId;
	long itsDate;
	double itsHours;

};

#endif // !__TIMECARDTRANSACTION_H__