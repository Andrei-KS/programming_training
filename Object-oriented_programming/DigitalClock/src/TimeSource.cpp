

#include "TimeSource.h"

TimeSource::TimeSource()
	: itsObservers(std::vector<interfaceClockObserver*>())
{
}

TimeSource::~TimeSource()
{
	itsObservers.clear();
}

void TimeSource::registerObserver(interfaceClockObserver* observer)
{
	itsObservers.push_back(observer);
}

void TimeSource::notify(int hours, int minutes, int seconds)
{
	for (std::vector<interfaceClockObserver*>::iterator it = itsObservers.begin(); it != itsObservers.end(); it++)
	{
		(*it)->update(hours, minutes, seconds);
	}
}

