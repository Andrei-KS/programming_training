

#include "BarometricPressureSensor.h"
#include "BarometricPressureSensorImp.h"

BarometricPressureSensor::BarometricPressureSensor(AlarmClock* AClock, StationToolkit* st)
	: itsBarometricPressureSensorImp(nullptr)
{
	if (st == nullptr)
	{
		throw("Error: BarometricPressureSensor(AlarmClock* AClock, StationToolkit* st): st is nullptr");
	}

	itsBarometricPressureSensorImp = st->makeBarometricPressure();
	if (itsBarometricPressureSensorImp == nullptr)
	{
		throw("Error: BarometricPressureSensor(AlarmClock* AClock, StationToolkit* st): st creat nullptr");
	}

	if (AClock != nullptr)
	{
		const int TimeIntervalForTemperatureSensote = 1000;
		itsListener.itsBarometricPressureSensor = this;
		AClock->wakeEvery(TimeIntervalForTemperatureSensote, &itsListener);
	}
	else
	{
		throw("Error: BarometricPressureSensor(AlarmClock* AClock, StationToolkit* st): AClock is nullptr");
	}
}

BarometricPressureSensor::~BarometricPressureSensor()
{
}

double BarometricPressureSensor::read()
{
	return itsBarometricPressureSensorImp->read();
}

void BarometricPressureSensor::check()
{
	double val = read();
	notifyObservers(val);
}