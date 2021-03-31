#ifndef __CLOCKDRIVER_H__
#define __CLOCKDRIVER_H__

#include "interfaceTimeSink.h"
#include "interfaceTimeSource.h"
#include "interfaceClockObserver.h"

class ClockDriver : public interfaceClockObserver
{
public:
	ClockDriver(interfaceTimeSource* source, interfaceTimeSink* sink);
	virtual void update(int hours, int minutes, int seconds) override;
private:
	interfaceTimeSink* itsSink;
};

#endif // !__CLOCKDRIVER_H__