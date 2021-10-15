#ifndef __WEATHERSTATION_H__
#define __WEATHERSTATION_H__

#include "WeatherStationComponent.h"
class TemperatureSensor;
class BarometricPressureSensor;
class BarometricPressureTrendSensor;
class AlarmClock;
class StationToolkit;

/**
* 
*/
class WeatherStation : public WeatherStationComponent
{
public:
	/**
	* 
	*/
	WeatherStation(StationToolkit* st);

	/**
	*
	*/
	~WeatherStation();

	/**
	* add Temperature Observer
	* @param observer - pointer to Observer
	*/
	virtual void addTempObserver(Observer* observer) override;

	/*
	* add Barometric Pressure Observer
	* @param observer - pointer to Observer
	*/
	virtual void addBPObserver(Observer* observer) override;

	/**
	* add Barometric Pressure Trend Observer
	* @param observer - pointer to Observer
	*/
	virtual void addBPTObserver(Observer* observer) override;

	/**
	* 
	*/
	AlarmClock* getAlarmClock();

private:
	/**  */
	TemperatureSensor* itsTS;

	/**  */
	BarometricPressureSensor* itsBPS;

	/**  */
	BarometricPressureTrendSensor* itsBPT;

	/**  */
	AlarmClock* itsAC;
};
#endif // !__WEATHERSTATION_H__