#ifndef __MOCKTIMESINK_H__
#define __MOCKTIMESINK_H__

#include "interfaceTimeSink.h"

class MockTimeSink : public interfaceTimeSink
{
public:
	int getSeconds();
	int getMinutes();
	int getHours();
	virtual void setTime(int hours, int minutes, int seconds) override;

private:
	int itsHours;
	int itsMinutes;
	int itsSeconds;
};

#endif // !__MOCKTIMESINK_H__