

#include "TemperatureObserver.h"
#include "MonitoringScreen.h"

TemperatureObserver::TemperatureObserver(MonitoringScreen* monitoringScreen)
	: ObserverMScreen(monitoringScreen)
{
}

void TemperatureObserver::update(double value)
{
	itsMonitoringScreen->displayTemp(value);
}