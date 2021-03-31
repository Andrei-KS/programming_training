#ifndef __MOCKTIMESOURCE_H__
#define __MOCKTIMESOURCE_H__

#include "TimeSource.h"

class MockTimeSource : public TimeSource
{
public:
	MockTimeSource();
	~MockTimeSource();
	void setTime(int hours, int minutes, int seconds);
};

#endif // !__MOCKTIMESOURCE_H__