#ifndef __MOCKTIMESOURCE_H__
#define __MOCKTIMESOURCE_H__

#include "interfaceTimeSource.h"

class MockTimeSource : public interfaceTimeSource
{
public:
	MockTimeSource();
	void setTime(int hours, int minutes, int seconds);
	virtual void setObserver(interfaceClockObserver* observer) override;

private:
	interfaceClockObserver* itsObserver;
};

#endif // !__MOCKTIMESOURCE_H__