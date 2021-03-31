#ifndef __INTERFACETIMESINK_H__
#define __INTERFACETIMESINK_H__

class interfaceTimeSink
{
public:
	virtual void setTime(int hours, int minutes, int seconds) = 0;
};

#endif // !__INTERFACETIMESINK_H__