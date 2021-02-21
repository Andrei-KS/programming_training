

#include "../../header/PaymentSchedule/BiweeklySchedule.h"

BiweeklySchedule::~BiweeklySchedule()
{
}

BiweeklySchedule::BiweeklySchedule()
{
}

bool BiweeklySchedule::IsPayday(const Date& date) const
{
	return false;
}
