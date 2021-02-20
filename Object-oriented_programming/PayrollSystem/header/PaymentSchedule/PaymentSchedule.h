#ifndef __PAYMENTSCHEDULE_H__
#define __PAYMENTSCHEDULE_H__

class PaymentSchedule
{
public:
	virtual ~PaymentSchedule();
	PaymentSchedule();
	virtual bool IsPayday(long date) const = 0;
};

#endif // !__PAYMENTSCHEDULE_H__