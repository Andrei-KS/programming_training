

#include "TestTemperatureSensor.h"
#include <random>

TestTemperatureSensor::TestTemperatureSensor(AlarmClock* AClock, int minValue, int maxValue)
	: TemperatureSensor(AClock)
	, itsValues(std::vector<double>(2,0))
	, itsIndex(0)
{
	itsTypeReadTest = TypeReadTestTemperatureSensor::Random;
	itsValues.at(0) = minValue;
	itsValues.at(1) = maxValue;
}

TestTemperatureSensor::TestTemperatureSensor(AlarmClock* AClock, const std::vector<double>& temperatureValues)
	: TemperatureSensor(AClock)
	, itsTypeReadTest(TypeReadTestTemperatureSensor::PresetValues)
	, itsValues(temperatureValues)
	, itsIndex(0)
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
		readedValue = itsValues.at(itsIndex);
		itsIndex = (itsIndex + 1) % itsValues.size();
	}
	return readedValue; 
}
