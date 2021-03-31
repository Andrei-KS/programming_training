

#include "ClockDriver.h"


ClockDriver::ClockDriver(interfaceTimeSource* source, interfaceTimeSink* sink)
	: itsSink(sink)
{
	source->setDriver(this);
}

void ClockDriver::update(int hours, int minutes, int seconds)
{
	itsSink->setTime(hours, minutes, seconds);
}
