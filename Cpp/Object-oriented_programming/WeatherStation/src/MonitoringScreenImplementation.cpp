

#include "MonitoringScreenImplementation.h"
#include <iostream>

MonitoringScreenImplementation::MonitoringScreenImplementation(WeatherStationComponent* wsc)
	: MonitoringScreen(wsc)
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