#ifndef __SERVICECHARGE_H__
#define __SERVICECHARGE_H__

class ServiceCharge
{
public:
	virtual ~ServiceCharge();
	ServiceCharge(long date, double amount);
	long GetDate() { return itsDate; }
	double GetAmount() { return itsAmount; }

private:
	long itsDate;
	double itsAmount;
};

#endif // !__SERVICECHARGE_H__