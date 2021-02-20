#ifndef __SALESRECEIPT_H__
#define __SALESRECEIPT_H__

class SalesReceipt
{
public:
	virtual ~SalesReceipt();
	SalesReceipt(long date, double amount);
	long GetDate() { return itsDate; }
	double GetAmount() { return itsAmount; }

private:
	long itsDate;
	double itsAmount;
};

#endif // !__SALESRECEIPT_H__