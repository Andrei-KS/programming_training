

#include "MonitoringScreen.h"

MonitoringScreen::MonitoringScreen(Observable* temperatureSensorObservable)
{
	MonitoringScreen* ms = this;
	temperatureSensorObservable->registerObserver(new TemperatureObserver(ms));
}