

#include "MonitoringScreen.h"
#include "TemperatureObserver.h"
#include "TemperatureSensor.h"
#include "BarometricPressureSensor.h"
#include "BarometricPressureObserver.h"

MonitoringScreen::MonitoringScreen(Observable* temperatureSensorObservable,
	Observable* barometricPressureSensorObservable)
{
	MonitoringScreen* ms = this;
	if (TemperatureSensor* ts = dynamic_cast<TemperatureSensor*>(temperatureSensorObservable))
	{
		ts->registerObserver(new TemperatureObserver(ms));
	}
	if (BarometricPressureSensor* bps = dynamic_cast<BarometricPressureSensor*>(barometricPressureSensorObservable))
	{
		bps->registerObserver(new BarometricPressureObserver(ms));
	}
}