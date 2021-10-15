#ifndef __BIWEEKLYSCHEDULE_H__
#define __BIWEEKLYSCHEDULE_H__

#include "PaymentSchedule.h"

class BiweeklySchedule : public PaymentSchedule
{
public:
	virtual ~BiweeklySchedule();
	BiweeklySchedule();
	virtual bool IsPayday(const Date& theDate) const override;
	virtual Date GetPayPeriodStartDate(const Date& payPeriodEndDate) const override;
};

#endif // !__BIWEEKLYSCHEDULE_H__