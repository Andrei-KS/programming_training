#ifndef __MONTHLYSCHEDULE_H__
#define __MONTHLYSCHEDULE_H__

#include "PayrollDomain/PaymentSchedule.h"

class MonthlySchedule : public PaymentSchedule
{
public:
	virtual ~MonthlySchedule();
	MonthlySchedule();
	virtual bool IsPayday(const Date& date) const override;
	virtual Date GetPayPeriodStartDate(const Date& payPeriodEndDate) const override;
};

#endif // !__MONTHLYSCHEDULE_H__