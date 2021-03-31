#ifndef __INTERFACETIMESOURCE_H__
#define __INTERFACETIMESOURCE_H__

#include "interfaceClockObserver.h"

class interfaceTimeSource
{
public:
	virtual void registerObserver(interfaceClockObserver* observer) = 0;
};

#endif // !__INTERFACETIMESOURCE_H__