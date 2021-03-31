

#include "MockTimeSource.h"
#include "ClockDriver.h"

void MockTimeSource::setTime(int hours, int minutes, int seconds)
{
	itsDriver->update(hours, minutes, seconds);
}

void MockTimeSource::setDriver(ClockDriver* driver)
{
	itsDriver = driver;
}
