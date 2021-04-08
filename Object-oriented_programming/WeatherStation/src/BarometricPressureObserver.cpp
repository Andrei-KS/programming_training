

#include "BarometricPressureObserver.h"
#include "MonitoringScreen.h"

BarometricPressureObserver::BarometricPressureObserver(MonitoringScreen* monitoringScreen)
	: ObserverMScreen(monitoringScreen)
{
}

void BarometricPressureObserver::update(double value)
{
	itsMonitoringScreen->displayPressure(value);
}