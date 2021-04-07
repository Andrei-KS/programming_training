#ifndef __TEMPERATUREOBSERVER_H__
#define __TEMPERATUREOBSERVER_H__

#include"ObserverMScreen.h"

/**
* Description of class TemperatureObserver
*
* TemperatureObserver monitors temperature sensors and,
* when the state of the observed object changes,
* transmits new temperature data to the monitorScreen. 
*
* @see ObserverMScreen, MonitoringScreen, Observable
*/
class TemperatureObserver : public ObserverMScreen
{
public:
	/**
	* When creating an observer, it binds to the MonitoringScreen object
	* @see MonitoringScreen
	*/
	TemperatureObserver(MonitoringScreen* monitoringScreen);
	
	/**
	* This function is activated when Observable is changed
	* @param value - the value obtained from the observed subject
	* @see Observable
	*/
	virtual void update(double value) override;
};

#endif // !__TEMPERATUREOBSERVER_H__