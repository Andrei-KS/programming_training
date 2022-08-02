#ifndef __TIMESOURCE_H__
#define __TIMESOURCE_H__

class TimeSource
{
public:
	virtual int getHours() = 0;
	virtual int getMinutes() = 0;
	virtual int getSeconds() = 0;
};

#endif // !__TIMESOURCE_H__