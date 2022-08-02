

#include "TemperatureSensor.h"
#include "TemperatureType.h"
#include "TemperatureSensorImp.h"

TemperatureSensor::TemperatureSensor(AlarmClock* AClock, StationToolkit* st)
	: itsLastReading(MinTemperature)
{
	if (st == nullptr)
	{
		throw("Error: TemperatureSensor(AlarmClock* AClock, StationToolkit* st): st is nullptr");
	}
	
	itsTemperatureSensorImp = st->makeTemperature();
	if (itsTemperatureSensorImp == nullptr)
	{
		throw("Error: TemperatureSensor(AlarmClock* AClock, StationToolkit* st): st creat nullptr");
	}

	if (AClock != nullptr)
	{
		const int TimeIntervalForTemperatureSensote = 1000;
		itsListener.itsTemperatureSensor = this;
		AClock->wakeEvery(TimeIntervalForTemperatureSensote, &itsListener);
	}
	else
	{
		throw("Error: TemperatureSensor(AlarmClock* AClock, StationToolkit* st): AClock is nullptr");
	}
}

TemperatureSensor::~TemperatureSensor()
{
}

double TemperatureSensor::read()
{
	return itsTemperatureSensorImp->read();
}

void TemperatureSensor::check()
{
	double val = read();
	if (val != itsLastReading)
	{
		itsLastReading = val;
		notifyObservers(val);
	}
}