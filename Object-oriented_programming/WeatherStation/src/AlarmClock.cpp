

#include "AlarmClock.h"
#include "AlarmClockImp.h"

AlarmClock::AlarmClock(StationToolkit* st)
	: itsAlarmListners(std::vector<AlarmListener*>())
{
	if (st == nullptr)
	{
		throw ("Error: AlarmClock::AlarmClock(StationToolkit* st): st is nullptr");
	}
	st->getAlarmClock()->registerClockListner(this);
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

void AlarmClock::tic()
{
	wakeupAll();
	//TODO check listener and if it need wake up then it wake up this listner
}