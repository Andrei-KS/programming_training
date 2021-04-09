

#include "MonitoringScreen.h"
#include "TemperatureObserver.h"
#include "TemperatureSensor.h"
#include "BarometricPressureSensor.h"
#include "BarometricPressureObserver.h"
#include "BarometricPressureTrendSensor.h"
#include "BarometricPressureTrendObserver.h"

MonitoringScreen::MonitoringScreen(Observable* temperatureSensorObservable,	Observable* barometricPressureSensorObservable, Observable* barometricPressureTrendSensorObservable)
{
	//MonitoringScreen* ms = this;
	if (TemperatureSensor* ts = dynamic_cast<TemperatureSensor*>(temperatureSensorObservable))
	{
		ts->registerObserver(new TemperatureObserver(this));
	}
	if (BarometricPressureSensor* bps = dynamic_cast<BarometricPressureSensor*>(barometricPressureSensorObservable))
	{
		bps->registerObserver(new BarometricPressureObserver(this));
	}
	if (BarometricPressureTrendSensor* bpts = dynamic_cast<BarometricPressureTrendSensor*>(barometricPressureTrendSensorObservable))
	{
		bpts->registerObserver(new BarometricPressureTrendObserver(this));
	}
}