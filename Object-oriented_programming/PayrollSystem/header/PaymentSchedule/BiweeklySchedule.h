#ifndef __BIWEEKLYSCHEDULE_H__
#define __BIWEEKLYSCHEDULE_H__

#include "PaymentSchedule.h"

class BiweeklySchedule : public PaymentSchedule
{
public:
	virtual ~BiweeklySchedule();
	BiweeklySchedule();
	virtual bool IsPayday(const Date& date) const override;
};

#endif // !__BIWEEKLYSCHEDULE_H__