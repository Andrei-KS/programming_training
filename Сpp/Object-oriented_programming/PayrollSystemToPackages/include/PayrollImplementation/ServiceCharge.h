#ifndef __SERVICECHARGE_H__
#define __SERVICECHARGE_H__

#include "Date/Date.h"

class ServiceCharge
{
public:
	virtual ~ServiceCharge();
	ServiceCharge(const Date& date, double amount);
	Date GetDate() const { return itsDate; }
	double GetAmount() const { return itsAmount; }

private:
	Date itsDate;
	double itsAmount;
};

#endif // !__SERVICECHARGE_H__