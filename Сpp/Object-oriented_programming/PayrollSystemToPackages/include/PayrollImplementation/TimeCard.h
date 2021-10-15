#ifndef __TIMECARD_H__
#define __TIMECARD_H__

#include "Date/Date.h"

class TimeCard
{
public:
	virtual ~TimeCard();
	TimeCard(const Date& date, double hours);
	Date GetDate() const { return itsDate; }
	double GetHours() const { return itsHours; }

private:
	Date itsDate;
	double itsHours;

};

#endif // !__TIMECARD_H__