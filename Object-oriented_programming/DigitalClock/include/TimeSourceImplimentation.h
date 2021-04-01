#ifndef __TIMESOURCEIMPLIMENTATION_H__
#define __TIMESOURCEIMPLIMENTATION_H__

#include "interfaceClockObserver.h"
#include <vector>

class TimeSourceImplimentation
{
public:
	TimeSourceImplimentation();
	~TimeSourceImplimentation();
	void notify(int hours, int minutes, int seconds);
	void registerObserver(interfaceClockObserver* observer);
private:
	std::vector<interfaceClockObserver*> itsObservers;
};

#endif // !__TIMESOURCEIMPLIMENTATION_H__