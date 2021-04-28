

#include "TemperatureSensor.h"
#include "TemperatureType.h"

TemperatureSensor::TemperatureSensor(AlarmClock* AClock)
	: itsLastReading(MinTemperature)
{
	if (AClock != nullptr)
	{
		const int TimeIntervalForTemperatureSensote = 1000;
		itsListener.itsTemperatureSensor = this;
		AClock->wakeEvery(TimeIntervalForTemperatureSensote, &itsListener);
	}
	else
	{
		throw("Error: TemperatureSensor(AlarmClock* AClock): AClock is nullptr");
	}
}

TemperatureSensor::~TemperatureSensor()
{
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