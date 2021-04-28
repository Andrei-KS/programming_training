#include "..\include\AlarmClock.h"

AlarmClock::AlarmClock()
	: itsAlarmListners(std::vector<AlarmListener*>())
{
}

AlarmClock::~AlarmClock()
{
}

void AlarmClock::wakeEvery(int interval, AlarmListener* AListner)
{
	itsAlarmListners.push_back(AListner);
}

void AlarmClock::wakeupAll() const
{
	for (std::vector<AlarmListener*>::const_iterator cit = itsAlarmListners.cbegin(); cit != itsAlarmListners.cend(); cit++)
	{
		(*cit)->wakeup();
	}
}
