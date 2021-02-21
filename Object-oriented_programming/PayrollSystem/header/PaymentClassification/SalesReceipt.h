#ifndef __SALESRECEIPT_H__
#define __SALESRECEIPT_H__

#include "../Date.h"

class SalesReceipt
{
public:
	virtual ~SalesReceipt();
	SalesReceipt(const Date& date, double amount);
	Date GetDate() const { return itsDate; }
	double GetAmount() const { return itsAmount; }

private:
	Date itsDate;
	double itsAmount;
};

#endif // !__SALESRECEIPT_H__