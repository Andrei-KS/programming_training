

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

Date WeeklySchedule::GetPayPeriodStartDate(const Date& payPeriodEndDate) const
{
	const char AmountOfDaysBeforeThePreviousMonday = 5;
	return payPeriodEndDate - AmountOfDaysBeforeThePreviousMonday;
}
