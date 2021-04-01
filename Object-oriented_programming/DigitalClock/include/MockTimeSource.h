#ifndef __MOCKTIMESOURCE_H__
#define __MOCKTIMESOURCE_H__

#include "TimeSource.h"
#include "TimeSourceImplimentation.h"

class MockTimeSource : public TimeSource
{
public:
	MockTimeSource();
	virtual ~MockTimeSource();
	void setTime(int hours, int minutes, int seconds);
	virtual void registerObserver(interfaceClockObserver* observer) override;

private:
	TimeSourceImplimentation* tsImp;
};

#endif // !__MOCKTIMESOURCE_H__