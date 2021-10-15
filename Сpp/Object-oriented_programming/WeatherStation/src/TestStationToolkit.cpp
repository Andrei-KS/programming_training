

#include "TestStationToolkit.h"
#include "PersistentImp.h"

TestStationToolkit::TestStationToolkit()
	: itsAlarmClockImp(nullptr)
	, itsPersistentImp(nullptr)
{
}

TestStationToolkit::~TestStationToolkit()
{
	delete itsAlarmClockImp;
	delete itsPersistentImp;
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

PersistentImp* TestStationToolkit::getPersistentImp()
{
	if (itsPersistentImp == nullptr)
	{
		itsPersistentImp = new PersistentImp("_StorageForData");
	}
	return itsPersistentImp;
}