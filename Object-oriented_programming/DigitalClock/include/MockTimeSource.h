#ifndef __MOCKTIMESOURCE_H__
#define __MOCKTIMESOURCE_H__

#include "interfaceTimeSource.h"
#include <vector>

class MockTimeSource : public interfaceTimeSource
{
public:
	MockTimeSource();
	~MockTimeSource();
	void setTime(int hours, int minutes, int seconds);
	virtual void registerObserver(interfaceClockObserver* observer) override;

private:
	std::vector<interfaceClockObserver*> itsObservers;
};

#endif // !__MOCKTIMESOURCE_H__