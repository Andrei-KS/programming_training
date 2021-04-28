

#include "TestMonitoringScreenImplementation.h"
#include "Observable.h"

TestMonitoringScreenImplementation::TestMonitoringScreenImplementation(Observable* temperatureSensorObservable, Observable* barometricPressureSensorObservable, Observable* barometricPressureTrendSensorObservable)
	: MonitoringScreen(temperatureSensorObservable, barometricPressureSensorObservable, barometricPressureTrendSensorObservable)
	, itsPressure(0)
	, itsPressureTrend(0)
	, itsTemp(0)
{

}

void TestMonitoringScreenImplementation::displayTemp(double value)
{
	itsTemp = value;
}

void TestMonitoringScreenImplementation::displayPressure(double value)
{
	itsPressure = value;
}

void TestMonitoringScreenImplementation::displayPressureTrend(double value)
{
	itsPressureTrend = value;
}
