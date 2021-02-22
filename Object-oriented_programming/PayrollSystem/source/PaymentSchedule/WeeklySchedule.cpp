

#include "../../header/PaymentSchedule/WeeklySchedule.h"

WeeklySchedule::~WeeklySchedule()
{
}

WeeklySchedule::WeeklySchedule()
{
}

bool WeeklySchedule::IsPayday(const Date& date) const
{
	return date.GetDayOfWeek() == Date::Friday;
}
