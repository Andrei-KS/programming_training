

#include "MockTimeSource.h"

MockTimeSource::MockTimeSource()
	: itsHours(0)
	, itsMinutes(0)
	, itsSeconds(0)
{
}

MockTimeSource::~MockTimeSource()
{
}

void MockTimeSource::setTime(int hours, int minutes, int seconds)
{
	itsHours = hours;
	itsMinutes = minutes;
	itsSeconds = seconds;
	notifyObservers();
}

int MockTimeSource::getHours()
{
	return itsHours;
}

int MockTimeSource::getMinutes()
{
	return itsMinutes;
}

int MockTimeSource::getSeconds()
{
	return itsSeconds;
}
