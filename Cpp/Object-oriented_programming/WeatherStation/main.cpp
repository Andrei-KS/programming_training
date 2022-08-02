

#include "StationToolkit.h"
#include "WeatherStation.h"
#include "MonitoringScreenImplementation.h"
#include "TestStationToolkit.h"

#include "HiLoDataImp.h"
#include "Date.h"

int main(int argc, char* argv[])
{
	TestStationToolkit tst;
	WeatherStation* ws = new WeatherStation(&tst);
	MonitoringScreenImplementation* msi = new MonitoringScreenImplementation(ws);
	TestAlarmClockImp* taci = dynamic_cast<TestAlarmClockImp*>(tst.getAlarmClock());
	taci->run();

	HiLoDataImp hldi(&tst,HiLoDataImp::Type::Temperature,Date(2,3,2020),10,10);
	hldi.currentReading(10, 20);
	hldi.newDay(13,0);
	return 0;
}