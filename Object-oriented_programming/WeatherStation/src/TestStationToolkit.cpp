

#include "TestStationToolkit.h"

TemperatureSensorImp* TestStationToolkit::makeTemperature()
{
	return new TestTemperatureSensor(-35,35);
}

BarometricPressureSensorImp* TestStationToolkit::makeBarometricPressure()
{
	return new TestBarometricPressureSensor(360,365);
}