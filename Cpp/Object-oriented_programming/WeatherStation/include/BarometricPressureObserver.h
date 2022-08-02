#ifndef __BAROMETRICPRESSUREOBSERVER_H__
#define __BAROMETRICPRESSUREOBSERVER_H__

#include "ObserverMScreen.h"
class MonitoringScreen;

/**
* Description of class BarometricPressureObserver
*
* TemperatureObserver monitors barometric pressure sensors and,
* when the state of the observed object changes,
* transmits new pressure data to the monitorScreen.
*
* @see ObserverMScreen, MonitoringScreen, Observable
*/
class BarometricPressureObserver : public ObserverMScreen
{
public:
	/**
	* When creating an observer, it binds to the MonitoringScreen object
	* @param monitoringScreen - a monitoring screen that will be notified when the observed object changes
	* @see MonitoringScreen
	*/
	BarometricPressureObserver(MonitoringScreen* monitoringScreen);

	/**
	* This function is activated when Observable is changed
	* @param value - the value obtained from the observed subject
	* @see Observable
	*/
	virtual void update(double value) override;
};

#endif // !__BAROMETRICPRESSUREOBSERVER_H__