
#include "TemperatureSensor.h"
#include "BarometricPressureSensor.h"
#include "StationToolkit.h"

#include "TestTemperatureSensor.h"
#include "TestBarometricPressureSensor.h"
#include "MonitoringScreenImplementation.h"
#include "BarometricPressureTrendSensor.h"
#include "AlarmClock.h"
#include "TestStationToolkit.h"
#include "TestAlarmClockImp.h"

int main(int argc, char* argv[])
{
	StationToolkit* st = new TestStationToolkit();
	AlarmClock* ac = new AlarmClock(st);
	TemperatureSensor* ts = new TemperatureSensor(ac, st);
	BarometricPressureSensor* bps = new BarometricPressureSensor(ac, st);
	BarometricPressureTrendSensor* bpts = new BarometricPressureTrendSensor(bps);

	MonitoringScreenImplementation msi(ts, bps, bpts);
	TestAlarmClockImp* taci = dynamic_cast<TestAlarmClockImp*>(st->getAlarmClock());
	taci->run();

	delete bpts;
	delete bps;
	delete ts;
	delete ac;
	delete st;
	return 0;
}