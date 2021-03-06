#ifndef __PAYMENTSCHEDULE_H__
#define __PAYMENTSCHEDULE_H__

#include "Date/Date.h"

class PaymentSchedule
{
public:
	virtual ~PaymentSchedule();
	PaymentSchedule();
	virtual bool IsPayday(const Date& date) const = 0;
	virtual Date GetPayPeriodStartDate(const Date& payPeriodEndDate) const = 0;;
};

#endif // !__PAYMENTSCHEDULE_H__