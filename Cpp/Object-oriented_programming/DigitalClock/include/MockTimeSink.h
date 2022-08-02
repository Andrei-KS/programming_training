#ifndef __MOCKTIMESINK_H__
#define __MOCKTIMESINK_H__

#include "Observer.h"
#include "TimeSource.h"

class MockTimeSink : public Observer, public TimeSource
{
public:
	MockTimeSink(TimeSource* source);
	~MockTimeSink();
	virtual int getHours() override;
	virtual int getMinutes() override;
	virtual int getSeconds() override;
	virtual void update() override;

private:
	int itsHours;
	int itsMinutes;
	int itsSeconds;
	TimeSource* itsSource;
};

#endif // !__MOCKTIMESINK_H__