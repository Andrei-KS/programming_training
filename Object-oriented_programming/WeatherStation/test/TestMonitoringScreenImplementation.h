#ifndef __TESTMONITORINGSCREENIMPLEMENTATION_H__
#define __TESTMONITORINGSCREENIMPLEMENTATION_H__

#include "MonitoringScreen.h"

/**
* Description of class MonitoringScreenImplementation
*
* Implementation of MonitoringScreen. Standard output is used to output data.
* @see MonitoringScreen
*/
class TestMonitoringScreenImplementation : public MonitoringScreen
{
public:
	/**
	* Ñonstructor for creating a new MonitoringScreenImplementation.
	*
	* While creating Monitor Screen it create Observers and register they to correspondent Observable objects
	* @param temperatureSensorObservable - Observable objects correspond temperature sensor
	* @param barometricPressureSensorObservable - Observable objects correspond barometric pressure sensor
	* @see Observable, Observer, TemperatureObserver, BarometricPressureObserver
	*/
	TestMonitoringScreenImplementation(Observable* temperatureSensorObservable, Observable* barometricPressureSensorObservable, Observable* barometricPressureTrendSensorObservable);

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

	/**
	* Function display pressure trend reading from pressure sensor
	* @param value - this pressure trend value will display
	*/
	virtual void displayPressureTrend(double value) override;
	
	/**
	* 
	*/
	double getTemp() { return itsTemp; }

	/**
	* 
	*/
	double getPressure() { return itsPressure; }

	/**
	* 
	*/
	double getPressureTrend() { return itsPressureTrend; }

private:
	double itsTemp;
	double itsPressure;
	double itsPressureTrend;
};
#endif // !__TESTMONITORINGSCREENIMPLEMENTATION_H__