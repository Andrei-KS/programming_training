#ifndef __BAROMETRICPRESSURETRENDOBSERVER_H__
#define __BAROMETRICPRESSURETRENDOBSERVER_H__


#include "ObserverMScreen.h"
class MonitoringScreen;

/**
* Description of class BarometricPressureTrendObserver
*
* TemperatureObserver monitors barometric pressure trend sensors and,
* when the state of the observed object changes,
* transmits new pressure data to the monitorScreen.
*
* @see ObserverMScreen, MonitoringScreen, Observable
*/

class BarometricPressureTrendObserver : public ObserverMScreen
{
public:
	/**
	* When creating an observer, it binds to the MonitoringScreen object
	* @param monitoringScreen - a monitoring screen that will be notified when the observed object changes
	* @see MonitoringScreen
	*/
	BarometricPressureTrendObserver(MonitoringScreen* monitoringScreen);

	/**
	* This function is activated when Observable is changed
	* @param value - the value obtained from the observed subject
	* @see Observable
	*/
	virtual void update(double value) override;
};

#endif // !__BAROMETRICPRESSURETRENDOBSERVER_H__