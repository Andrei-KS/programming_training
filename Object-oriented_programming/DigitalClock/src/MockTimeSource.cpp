

#include "MockTimeSource.h"
#include "ClockDriver.h"

void MockTimeSource::setTime(int hours, int minutes, int seconds)
{
	itsObserver->update(hours, minutes, seconds);
}

void MockTimeSource::setObserver(interfaceClockObserver* observer)
{
	itsObserver = observer;
}
