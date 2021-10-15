

#include "BarometricPressureTrendObserver.h"
#include "MonitoringScreen.h"

BarometricPressureTrendObserver::BarometricPressureTrendObserver(MonitoringScreen* monitoringScreen)
	: ObserverMScreen(monitoringScreen)
{
}


void BarometricPressureTrendObserver::update(double value)
{
	itsMonitoringScreen->displayPressureTrend(value);
}