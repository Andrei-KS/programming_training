

#include "TestStationToolkit.h"

TestStationToolkit::TestStationToolkit()
	: itsAlarmClockImp(nullptr)
{
}

TestStationToolkit::~TestStationToolkit()
{
	delete itsAlarmClockImp;
}

TemperatureSensorImp* TestStationToolkit::makeTemperature()
{
	return new TestTemperatureSensor(-35,35);
}

BarometricPressureSensorImp* TestStationToolkit::makeBarometricPressure()
{
	return new TestBarometricPressureSensor(360,365);
}

AlarmClockImp* TestStationToolkit::getAlarmClock()
{
	if (itsAlarmClockImp == nullptr)
	{
		itsAlarmClockImp = new TestAlarmClockImp();
	}
	return itsAlarmClockImp;
}