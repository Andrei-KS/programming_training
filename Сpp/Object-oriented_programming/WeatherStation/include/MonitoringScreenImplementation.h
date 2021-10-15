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
	* Ñonstructor for creating a new MonitoringScreenImplementation.
	*
	* While creating Monitor Screen it create Observers and register they to correspondent Observable objects
	* @param wsc - pointer to WeatherStationComponent that registers this object as an observer of it
	* @see Observable, Observer, WeatherStationComponent
	*/
	MonitoringScreenImplementation(WeatherStationComponent* wsc);

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
};
#endif // !__MONITORINGSCREENIMPLEMENTATION_H__