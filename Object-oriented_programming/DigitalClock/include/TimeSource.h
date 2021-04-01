#ifndef __TIMESOURCE_H__
#define __TIMESOURCE_H__

#include "interfaceClockObserver.h"

class TimeSource
{
public:
	TimeSource();
	virtual ~TimeSource();
	virtual void registerObserver(interfaceClockObserver* observer) = 0;;
};

#endif // !__TIMESOURCE_H__