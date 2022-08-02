#ifndef __OBSERVERMSCREEN_H__
#define __OBSERVERMSCREEN_H__

#include "Observer.h"
class MonitoringScreen;

/**
* Description of class inteface ObserverMScreen
*
* This class binds the observer to the monitoring screen object.
*
* @see Observer, MonitoringScreen
*/
class ObserverMScreen : public Observer
{
public:
	/**
	* When creating an observer, it binds to the MonitoringScreen object 
	*/
	ObserverMScreen(MonitoringScreen* monitoringScreen);

protected:
	/**
	* monitor screen associated with the observer
	*/
	MonitoringScreen* itsMonitoringScreen;
};

#endif // !__OBSERVERMSCREEN_H__