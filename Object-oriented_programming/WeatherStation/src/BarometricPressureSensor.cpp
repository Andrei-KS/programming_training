

#include "BarometricPressureSensor.h"
#include "BarometricPressureSensorImp.h"

BarometricPressureSensor::BarometricPressureSensor(AlarmClock* AClock, BarometricPressureSensorImp* BPSImp)
	: itsBarometricPressureSensorImp(BPSImp)
{
	if (itsBarometricPressureSensorImp == nullptr)
	{
		throw("Error: BarometricPressureSensor(AlarmClock* AClock, BarometricPressureSensorImp* BPSImp): BPSImp is nullptr");
	}

	if (AClock != nullptr)
	{
		const int TimeIntervalForTemperatureSensote = 1000;
		itsListener.itsBarometricPressureSensor = this;
		AClock->wakeEvery(TimeIntervalForTemperatureSensote, &itsListener);
	}
	else
	{
		throw("Error: BarometricPressureSensor(AlarmClock* AClock, BarometricPressureSensorImp* BPSImp): AClock is nullptr");
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