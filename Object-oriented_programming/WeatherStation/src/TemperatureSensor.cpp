

#include "TemperatureSensor.h"
#include "TemperatureType.h"
#include "TemperatureSensorImp.h"

TemperatureSensor::TemperatureSensor(AlarmClock* AClock, TemperatureSensorImp* TSImp)
	: itsLastReading(MinTemperature)
	, itsTemperatureSensorImp(TSImp)
{
	if (itsTemperatureSensorImp == nullptr)
	{
		throw("Error: TemperatureSensor(AlarmClock* AClock, TemperatureSensorImp* TSImp): TSImp is nullptr");
	}

	if (AClock != nullptr)
	{
		const int TimeIntervalForTemperatureSensote = 1000;
		itsListener.itsTemperatureSensor = this;
		AClock->wakeEvery(TimeIntervalForTemperatureSensote, &itsListener);
	}
	else
	{
		throw("Error: TemperatureSensor(AlarmClock* AClock, TemperatureSensorImp* TSImp): AClock is nullptr");
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