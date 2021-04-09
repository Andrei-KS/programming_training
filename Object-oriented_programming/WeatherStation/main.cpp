
#include "TestTemperatureSensor.h"
#include "TestBarometricPressureSensor.h"
#include "MonitoringScreenImplementation.h"

int main(int argc, char* argv[])
{
	TestTemperatureSensor tts(-10,10);
	TestBarometricPressureSensor tbps(350, 360), tbps2(340,350);
	MonitoringScreenImplementation msi(&tts, &tbps);
	MonitoringScreenImplementation msi2(&tts, &tbps2);
	MonitoringScreenImplementation msi3(&tbps, &tbps2);
	tts.read();
	tbps.read();
	tbps2.read();
	return 0;
}