#ifndef __MOCKTIMESOURCE_H__
#define __MOCKTIMESOURCE_H__

#include "TimeSource.h"
#include "Subject.h"

class MockTimeSource : public TimeSource, public Subject
{
public:
	MockTimeSource();
	virtual ~MockTimeSource();
	void setTime(int hours, int minutes, int seconds);
	virtual int getHours();
	virtual int getMinutes();
	virtual int getSeconds();

private:
	int itsHours;
	int itsMinutes;
	int itsSeconds;
};

#endif // !__MOCKTIMESOURCE_H__