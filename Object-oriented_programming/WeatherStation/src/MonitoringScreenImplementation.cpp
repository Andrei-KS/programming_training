

#include "MonitoringScreenImplementation.h"
#include <iostream>

MonitoringScreenImplementation::MonitoringScreenImplementation(Observable* temperatureSensorObservable, Observable* barometricPressureSensorObservable, Observable* barometricPressureTrendSensorObservable)
	: MonitoringScreen(temperatureSensorObservable, barometricPressureSensorObservable, barometricPressureTrendSensorObservable)
{
}

void MonitoringScreenImplementation::displayTemp(double value)
{
	std::cout << "Temperature:\t\t" << value << std::endl;
}

void MonitoringScreenImplementation::displayPressure(double value)
{
	std::cout << "Pressure:\t\t" << value << std::endl;
}

void MonitoringScreenImplementation::displayPressureTrend(double value)
{
	std::cout << "Pressure Trend:\t\t" << value << std::endl;
}