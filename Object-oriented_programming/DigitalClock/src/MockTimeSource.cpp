

#include "MockTimeSource.h"
#include "interfaceClockObserver.h"

MockTimeSource::MockTimeSource()
	: itsObservers(std::vector<interfaceClockObserver*>())
{
}

MockTimeSource::~MockTimeSource()
{
	itsObservers.clear();
}

void MockTimeSource::setTime(int hours, int minutes, int seconds)
{
	for (std::vector<interfaceClockObserver*>::iterator it = itsObservers.begin(); it != itsObservers.end(); it++)
	{
		(*it)->update(hours, minutes, seconds);
	}
}

void MockTimeSource::registerObserver(interfaceClockObserver* observer)
{
	itsObservers.push_back(observer);
}
