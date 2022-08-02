#ifndef __PAYDAYTRANSACTION_H__
#define __PAYDAYTRANSACTION_H__

#include "TransactionApplication/Transaction.h"
#include "Date/Date.h"

#include <unordered_map>

class Paycheck;

class PaydayTransaction : public Transaction
{
public:
	virtual ~PaydayTransaction();
	PaydayTransaction(const Date& date);
	virtual void Execute() override;
	Paycheck* GetPaycheck(int empId) const;

private:
	Date itsPayDate;
	std::unordered_map<int, Paycheck*> itsPaychecks;
};

#endif // !__PAYDAYTRANSACTION_H__