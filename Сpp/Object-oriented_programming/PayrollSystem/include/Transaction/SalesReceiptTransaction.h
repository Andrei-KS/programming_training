#ifndef __SALESRECEIPTTRANSACTION_H__
#define __SALESRECEIPTTRANSACTION_H__

#include "Transaction.h"
#include "../Date.h"

class SalesReceiptTransaction : public Transaction
{
public:
	virtual ~SalesReceiptTransaction();
	SalesReceiptTransaction(const Date& date, double amount, int empId);
	virtual void Execute() override;

private:
	int itsEmpId;
	Date itsDate;
	double itsAmount;
};

#endif // !__SALESRECEIPTTRANSACTION_H__