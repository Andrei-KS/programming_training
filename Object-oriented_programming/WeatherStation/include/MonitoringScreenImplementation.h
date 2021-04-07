#ifndef __MONITORINGSCREENIMPLEMENTATION_H__
#define __MONITORINGSCREENIMPLEMENTATION_H__

#include "MonitoringScreen.h"

/**
* Description of class MonitoringScreenImplementation
*
* Implementation of MonitoringScreen. Standard output is used to output data.
* @see MonitoringScreen
*/
class MonitoringScreenImplementation : public MonitoringScreen
{
public:
	/**
	* —onstructor for creating a new MonitoringScreenImplementation.
	*
	* While creating MonitoringScreenImplementation it create Observers and register they to correspondent Observable objects
	* @param temperatureSensorObservable - Observable objects correspond temperature sensor
	* @see Observable, Observer, TemperatureObserver
	*/
	MonitoringScreenImplementation(Observable* temperatureSensorObservable);

	/**
	* Function display temperature reading from temperature sensor
	* @param value - this temperature value will display
	*/
	virtual void displayTemp(double value) override;

	/**
	* Function display pressure reading from pressure sensor
	* @param value - this pressure value will display
	*/
	virtual void displayPressure(double value) override;
};
#endif // !__MONITORINGSCREENIMPLEMENTATION_H__