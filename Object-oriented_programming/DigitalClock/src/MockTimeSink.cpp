

#include "MockTimeSink.h"

MockTimeSink::MockTimeSink()
	: itsHours(0)
	, itsMinutes(0)
	, itsSeconds(0)
{
}

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

void MockTimeSink::update(int hours, int minutes, int seconds)
{
	itsHours = hours;
	itsMinutes = minutes;
	itsSeconds = seconds;
}
