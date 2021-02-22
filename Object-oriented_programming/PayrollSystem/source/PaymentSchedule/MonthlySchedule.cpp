

#include "../../header/PaymentSchedule/MonthlySchedule.h"

namespace
{
	bool IsLastDayOfMonth(const Date& date)
	{
		int m1 = date.GetMonth();
		int m2 = (date + 1).GetMonth();
		return (m1 != m2);
	}
}

MonthlySchedule::~MonthlySchedule()
{
}

MonthlySchedule::MonthlySchedule()
{
}


bool MonthlySchedule::IsPayday(const Date& date) const
{
	return IsLastDayOfMonth(date);
}
