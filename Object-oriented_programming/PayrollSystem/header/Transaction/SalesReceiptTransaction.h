#ifndef __SALESRECEIPTTRANSACTION_H__
#define __SALESRECEIPTTRANSACTION_H__

#include "Transaction.h"

class SalesReceiptTransaction : public Transaction
{
public:
	virtual ~SalesReceiptTransaction();
	SalesReceiptTransaction(long date, double amount, int empId);
	virtual void Execute() override;

private:
	int itsEmpId;
	long itsDate;
	double itsAmount;
};

#endif // !__SALESRECEIPTTRANSACTION_H__