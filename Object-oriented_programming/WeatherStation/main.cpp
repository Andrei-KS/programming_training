

#include "StationToolkit.h"
#include "WeatherStation.h"
#include "MonitoringScreenImplementation.h"
#include "TestStationToolkit.h"


int main(int argc, char* argv[])
{
	TestStationToolkit tst;
	WeatherStation* ws = new WeatherStation(&tst);
	MonitoringScreenImplementation* msi = new MonitoringScreenImplementation(ws);
	TestAlarmClockImp* taci = dynamic_cast<TestAlarmClockImp*>(tst.getAlarmClock());
	taci->run();
	return 0;
}