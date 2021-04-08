#ifndef __MONITORINGSCREEN_H__
#define __MONITORINGSCREEN_H__

#include "Observable.h"

/**
* Description of class MonitoringScreen
*
* Monitoring Screen contained polymorph function for display sensors readings.
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
	* @param barometricPressureSensorObservable - Observable objects correspond barometric pressure sensor
	* @see Observable, Observer, TemperatureObserver, BarometricPressureObserver
	*/
	MonitoringScreen(Observable* temperatureSensorObservable, Observable* barometricPressureSensorObservable);
	
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