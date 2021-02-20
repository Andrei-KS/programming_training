#ifndef __BIWEEKLYSCHEDULE_H__
#define __BIWEEKLYSCHEDULE_H__

#include "PaymentSchedule.h"

class BiweeklySchedule : public PaymentSchedule
{
public:
	virtual ~BiweeklySchedule();
	BiweeklySchedule();
	virtual bool IsPayday(long date) const;
};

#endif // !__BIWEEKLYSCHEDULE_H__