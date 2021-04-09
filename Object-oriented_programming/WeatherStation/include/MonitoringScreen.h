#ifndef __MONITORINGSCREEN_H__
#define __MONITORINGSCREEN_H__

#include "Observable.h"

/**
* Description of class MonitoringScreen
*
* Monitoring Screen contained polymorph function for display sensors readings.
* 
* @see Observable, Observer, TemperatureObserver, BarometricPressureObserver, BarometricPressureTrendSensor
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
	* @param barometricPressureTrendSensorObservable - Observable objects correspond barometric pressure trend sensor
	* @see Observable, Observer, TemperatureObserver, BarometricPressureObserver, BarometricPressureTrendSensor
	*/
	MonitoringScreen(Observable* temperatureSensorObservable, Observable* barometricPressureSensorObservable, Observable* barometricPressureTrendSensorObservable);
	
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

	/**
	* Function display pressure trend reading from pressure sensor
	* @param value - this pressure trend value will display
	*/
	virtual void displayPressureTrend(double value) = 0;
};

#endif // !__MONITORINGSCREEN_H__