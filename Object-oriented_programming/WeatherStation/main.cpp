
#include "TemperatureSensor.h"
#include "BarometricPressureSensor.h"

#include "TestTemperatureSensor.h"
#include "TestBarometricPressureSensor.h"
#include "MonitoringScreenImplementation.h"
#include "BarometricPressureTrendSensor.h"
#include "AlarmClock.h"

int main(int argc, char* argv[])
{
	AlarmClock* ac = new AlarmClock();
	TemperatureSensor* ts = new TemperatureSensor(ac, new TestTemperatureSensor(-10, 10));
	BarometricPressureSensor* bps = new BarometricPressureSensor(ac, new TestBarometricPressureSensor(365, 380));
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