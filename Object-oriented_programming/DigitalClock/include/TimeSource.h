#ifndef __TIMESOURCE_H__
#define __TIMESOURCE_H__

#include "interfaceClockObserver.h"
#include <vector>

class TimeSource
{
public:
	TimeSource();
	~TimeSource();
	void registerObserver(interfaceClockObserver* observer);

protected:
	void notify(int hours, int minutes, int seconds);

private:
	std::vector<interfaceClockObserver*> itsObservers;
};

#endif // !__TIMESOURCE_H__