#ifndef __CLOCKDRIVER_H__
#define __CLOCKDRIVER_H__

#include "interfaceTimeSink.h"
#include "interfaceTimeSource.h"

class ClockDriver
{
public:
	ClockDriver(interfaceTimeSource* source, interfaceTimeSink* sink);
	void update(int hours, int minutes, int seconds);
private:
	interfaceTimeSink* itsSink;
};

#endif // !__CLOCKDRIVER_H__