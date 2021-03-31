

#include "MockTimeSink.h"

int MockTimeSink::getSeconds()
{
	return itsSeconds;
}

int MockTimeSink::getMinutes()
{
	return itsMinutes;
}

int MockTimeSink::getHours()
{
	return itsHours;
}

void MockTimeSink::setTime(int hours, int minutes, int seconds)
{
	itsHours = hours;
	itsMinutes = minutes;
	itsSeconds = seconds;
}
