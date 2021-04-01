

#include "TimeSourceImplimentation.h"
#include "..\include\TimeSourceImplimentation.h"

TimeSourceImplimentation::TimeSourceImplimentation()
	: itsObservers(std::vector<interfaceClockObserver*>())
{
}

TimeSourceImplimentation::~TimeSourceImplimentation()
{
	itsObservers.clear();
}

void TimeSourceImplimentation::notify(int hours, int minutes, int seconds)
{
	for (std::vector<interfaceClockObserver*>::iterator it = itsObservers.begin(); it != itsObservers.end(); it++)
	{
		(*it)->update(hours, minutes, seconds);
	}
}

void TimeSourceImplimentation::registerObserver(interfaceClockObserver* observer)
{
	itsObservers.push_back(observer);
}
