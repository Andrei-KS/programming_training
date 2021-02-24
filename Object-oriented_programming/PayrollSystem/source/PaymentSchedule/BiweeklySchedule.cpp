

#include "../../header/PaymentSchedule/BiweeklySchedule.h"

BiweeklySchedule::~BiweeklySchedule()
{
}

BiweeklySchedule::BiweeklySchedule()
{
}

bool BiweeklySchedule::IsPayday(const Date& theDate) const
{
	char shiftWeek = Date(1, 1, theDate.GetYear()).GetDayOfWeek() > Date::Friday ? 0 : 1;
	return theDate.GetDayOfWeek() == Date::Friday 
		&& ((theDate.GetAmountOfDaysPassedInCurrentYear()/7 + shiftWeek) % 2) == 0;
}

Date BiweeklySchedule::GetPayPeriodStartDate(const Date& payPeriodEndDate) const
{
	const char AmountOfDaysBeforeThePrePreviousMonday = 12;
	return payPeriodEndDate - AmountOfDaysBeforeThePrePreviousMonday;
}
