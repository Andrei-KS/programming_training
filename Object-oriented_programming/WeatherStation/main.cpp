
#include "TemperatureSensor.h"
#include "BarometricPressureSensor.h"
#include "StationToolkit.h"

#include "TestTemperatureSensor.h"
#include "TestBarometricPressureSensor.h"
#include "MonitoringScreenImplementation.h"
#include "BarometricPressureTrendSensor.h"
#include "AlarmClock.h"
#include "TestStationToolkit.h"

int main(int argc, char* argv[])
{
	AlarmClock* ac = new AlarmClock();
	StationToolkit* st = new TestStationToolkit();
	TemperatureSensor* ts = new TemperatureSensor(ac, st);
	BarometricPressureSensor* bps = new BarometricPressureSensor(ac, st);
	BarometricPressureTrendSensor* bpts = new BarometricPressureTrendSensor(bps);

	MonitoringScreenImplementation msi(ts, bps, bpts);
	int numberCall = 10;
	for (int i = 0; i < numberCall; i++)
	{
		ac->wakeupAll();
	}

	delete bpts;
	delete bps;
	delete ts;
	delete ac;
	return 0;
}