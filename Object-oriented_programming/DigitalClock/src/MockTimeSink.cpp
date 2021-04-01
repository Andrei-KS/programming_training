

#include "MockTimeSink.h"

MockTimeSink::MockTimeSink(TimeSource* source)
	: itsHours(0)
	, itsMinutes(0)
	, itsSeconds(0)
	, itsSource(source)
{
}

MockTimeSink::~MockTimeSink()
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

void MockTimeSink::update()
{
	itsHours = itsSource->getHours();
	itsMinutes = itsSource->getMinutes();
	itsSeconds = itsSource->getSeconds();
}
