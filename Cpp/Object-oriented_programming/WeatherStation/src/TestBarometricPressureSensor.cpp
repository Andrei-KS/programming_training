

#include "TestBarometricPressureSensor.h"
#include <random>

TestBarometricPressureSensor::TestBarometricPressureSensor(int minValue, int maxValue)
	: itsTypeReadTest(TypeReadTestBarometricPressureSensor::Random)
	, itsValues(std::vector<double>(2, 0))
	, itsIndex(0)
{
	//itsTypeReadTest = TypeReadTestBarometricPressureSensor::Random;
	itsValues.at(0) = minValue;
	itsValues.at(1) = maxValue;
}

TestBarometricPressureSensor::TestBarometricPressureSensor(const std::vector<double>& pressureValues)
	: itsTypeReadTest(TypeReadTestBarometricPressureSensor::PresetValues)
	, itsValues(pressureValues)
	, itsIndex(0)
{
	if (pressureValues.size() <= 0)
	{
		throw("Error: TestTemperatureSensor(const std::vector<double>& temperatureValues): size of temperature values vector cannot be empty");
	}
}

TestBarometricPressureSensor::~TestBarometricPressureSensor()
{
}

double TestBarometricPressureSensor::read()
{
	double readedValue = 0;
	if (itsTypeReadTest == TypeReadTestBarometricPressureSensor::Random)
	{
		double delta = itsValues[1] - itsValues[0];
		std::random_device rd;
		readedValue = static_cast<double>(rd()) / rd.max() * delta + itsValues[0];
	}
	else
	{
		readedValue = itsValues.at(itsIndex);
		itsIndex = (itsIndex + 1) % itsValues.size();
	}
	return readedValue;
}