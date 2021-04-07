#ifndef __MONITORINGSCREEN_H__
#define __MONITORINGSCREEN_H__

#include "Observable.h"
#include "TemperatureObserver.h"


/**
* Description of class MonitoringScreen
*
* MonitoringScreen contained polymorph function for display instrument readings.
* @see Scheduler
*/
class MonitoringScreen
{
public:
	/**
	* Ñonstructor for creating a new Monitor Screen.
	* 
	* While creating Monitor Screen it create Observers and register they to correspondent Observable objects
	* @param temperatureSensorObservable - Observable objects correspond temperature sensor
	* @see Observable, Observer, TemperatureObserver
	*/
	MonitoringScreen(Observable* temperatureSensorObservable);
	
	/**
	* Function display temperature reading from temperature sensor
	* @param value - this temperature value will display
	*/
	virtual void displayTemp(double value) = 0;
	
	/**
	* Function display pressure reading from pressure sensor
	* @param value - this pressure value will display
	*/
	virtual void displayPressure(double value) = 0;
};

#endif // !__MONITORINGSCREEN_H__