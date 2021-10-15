

#include "WeatherStation.h"
#include "StationToolkit.h"
#include "AlarmClock.h"
#include "TemperatureSensor.h"
#include "BarometricPressureSensor.h"
#include "BarometricPressureTrendSensor.h"

WeatherStation::WeatherStation(StationToolkit* st)
{
	itsAC = new AlarmClock(st);
	itsTS = new TemperatureSensor(itsAC, st);
	itsBPS = new BarometricPressureSensor(itsAC, st);
	itsBPT = new BarometricPressureTrendSensor(itsBPS);
}

WeatherStation::~WeatherStation()
{
	delete itsTS;
	delete itsBPT;
	delete itsBPS;
}

void WeatherStation::addTempObserver(Observer* observer)
{
	itsTS->registerObserver(observer);
}

void WeatherStation::addBPObserver(Observer* observer)
{
	itsBPS->registerObserver(observer);
}

void WeatherStation::addBPTObserver(Observer* observer)
{
	itsBPT->registerObserver(observer);
}

AlarmClock* WeatherStation::getAlarmClock()
{
	return itsAC;
}