#ifndef __INTERFACECLOCKOBSERVER_H__
#define __INTERFACECLOCKOBSERVER_H__

class interfaceClockObserver
{
public:
	virtual void update(int hours, int minutes, int seconds) = 0;
};

#endif // !__INTERFACECLOCKOBSERVER_H__