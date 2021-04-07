

#include "MonitoringScreenImplementation.h"
#include <iostream>

MonitoringScreenImplementation::MonitoringScreenImplementation(Observable* temperatureSensorObservable)
	: MonitoringScreen(temperatureSensorObservable)
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