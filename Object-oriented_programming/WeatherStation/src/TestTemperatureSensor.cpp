

#include "TestTemperatureSensor.h"
#include <random>

TestTemperatureSensor::TestTemperatureSensor(int minValue, int maxValue)
	: itsValues(std::vector<double>(2,0))
{
	itsTypeReadTest = TypeReadTestTemperatureSensor::Random;
	itsValues.at(0) = minValue;
	itsValues.at(1) = maxValue;
}

TestTemperatureSensor::TestTemperatureSensor(const std::vector<double>& temperatureValues)
	: itsTypeReadTest(TypeReadTestTemperatureSensor::PresetValues)
	, itsValues(temperatureValues)
{
	if(temperatureValues.size() <= 0)
	{
		throw("Error: TestTemperatureSensor(const std::vector<double>& temperatureValues): size of temperature values vector cannot be empty");
	}
}

TestTemperatureSensor::~TestTemperatureSensor()
{
}

double TestTemperatureSensor::read()
{
	double readedValue = 0;
	if (itsTypeReadTest == TypeReadTestTemperatureSensor::Random)
	{
		double delta = itsValues[1] - itsValues[0];
		std::random_device rd;
		readedValue = static_cast<double>(rd()) / rd.max() * delta + itsValues[0];
	}
	else
	{
		static int index = 0;
		readedValue = itsValues.at(index);
		index = (index + 1) % itsValues.size();
	}
	return readedValue; 
}
