

#include "MonitoringScreenImplementation.h"
#include <iostream>

MonitoringScreenImplementation::MonitoringScreenImplementation(Observable* temperatureSensorObservable, Observable* barometricPressureSensorObservable)
	: MonitoringScreen(temperatureSensorObservable, barometricPressureSensorObservable)
{
}

void MonitoringScreenImplementation::displayTemp(double value)
{
	std::cout << "Temperature:\t" << value << std::endl;
}

void MonitoringScreenImplementation::displayPressure(double value)
{
	std::cout << "Pressure:\t" << value << std::endl;
}