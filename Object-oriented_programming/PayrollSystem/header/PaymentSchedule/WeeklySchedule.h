#ifndef __WEEKLYSCHEDULE_H__
#define __WEEKLYSCHEDULE_H__

#include "PaymentSchedule.h"

class WeeklySchedule : public PaymentSchedule
{
public:
	virtual ~WeeklySchedule();
	WeeklySchedule();
	virtual bool IsPayday(const Date& date) const override;
};

#endif // !__WEEKLYSCHEDULE_H__