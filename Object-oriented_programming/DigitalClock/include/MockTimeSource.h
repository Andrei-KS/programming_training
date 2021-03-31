#ifndef __MOCKTIMESOURCE_H__
#define __MOCKTIMESOURCE_H__

#include "interfaceTimeSource.h"

class MockTimeSource : public interfaceTimeSource
{
public:
	void setTime(int hours, int minutes, int seconds);
	virtual void setDriver(ClockDriver* driver) override;

private:
	ClockDriver* itsDriver;
};

#endif // !__MOCKTIMESOURCE_H__