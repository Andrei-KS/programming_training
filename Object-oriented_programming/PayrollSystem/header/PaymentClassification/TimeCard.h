#ifndef __TIMECARD_H__
#define __TIMECARD_H__

class TimeCard
{
public:
	virtual ~TimeCard();
	TimeCard(long date, double hours);
	long GetDate() { return itsDate; }
	double GetHours() { return itsHours; }

private:
	long itsDate;
	double itsHours;

};

#endif // !__TIMECARD_H__