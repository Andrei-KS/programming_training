#ifndef __MOCKTIMESINK_H__
#define __MOCKTIMESINK_H__

#include "interfaceClockObserver.h"

class MockTimeSink : public interfaceClockObserver
{
public:
	MockTimeSink();
	int getSeconds();
	int getMinutes();
	int getHours();
	virtual void update(int hours, int minutes, int seconds) override;

private:
	int itsHours;
	int itsMinutes;
	int itsSeconds;
};

#endif // !__MOCKTIMESINK_H__