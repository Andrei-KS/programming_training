

#include "MockTimeSource.h"
#include "interfaceClockObserver.h"

MockTimeSource::MockTimeSource()
{
}

MockTimeSource::~MockTimeSource()
{
}

void MockTimeSource::setTime(int hours, int minutes, int seconds)
{
	notify(hours, minutes, seconds);
}
