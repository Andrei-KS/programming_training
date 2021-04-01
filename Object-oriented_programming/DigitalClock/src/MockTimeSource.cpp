

#include "MockTimeSource.h"
#include "interfaceClockObserver.h"

MockTimeSource::MockTimeSource()
	: tsImp(new TimeSourceImplimentation())
{
}

MockTimeSource::~MockTimeSource()
{
	delete tsImp;
}

void MockTimeSource::setTime(int hours, int minutes, int seconds)
{
	tsImp->notify(hours, minutes, seconds);
}

void MockTimeSource::registerObserver(interfaceClockObserver* observer)
{
	tsImp->registerObserver(observer);
}
