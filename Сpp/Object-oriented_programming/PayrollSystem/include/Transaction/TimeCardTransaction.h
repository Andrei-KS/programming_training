#ifndef __TIMECARDTRANSACTION_H__
#define __TIMECARDTRANSACTION_H__

#include "Transaction.h"
#include "../Date.h"

class TimeCardTransaction : public Transaction
{
public:
	virtual ~TimeCardTransaction();
	TimeCardTransaction(const Date& date, double hours, int empId);
	virtual void Execute() override;

private:
	int itsEmpId;
	Date itsDate;
	double itsHours;

};

#endif // !__TIMECARDTRANSACTION_H__