
#include "TestTemperatureSensor.h"
#include "MonitoringScreenImplementation.h"

int main(int argc, char* argv[])
{
	TestTemperatureSensor tts(-10,10);
	MonitoringScreenImplementation msi(&tts);
	MonitoringScreenImplementation msi2(&tts);
	tts.read();
	return 0;
}