

#include "MonitoringScreen.h"
#include "WeatherStationComponent.h"
#include "TemperatureObserver.h"
#include "BarometricPressureObserver.h"
#include "BarometricPressureTrendObserver.h"

MonitoringScreen::MonitoringScreen(WeatherStationComponent* wsc)
{
	wsc->addTempObserver(new TemperatureObserver(this));
	wsc->addBPObserver(new BarometricPressureObserver(this));
	wsc->addBPTObserver(new BarometricPressureTrendObserver(this));
}