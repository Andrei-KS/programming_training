#ifndef __INTERFACETIMESOURCE_H__
#define __INTERFACETIMESOURCE_H__

class ClockDriver;

class interfaceTimeSource
{
public:
	virtual void setDriver(ClockDriver* driver) = 0;
};

#endif // !__INTERFACETIMESOURCE_H__