

#include "TestTemperatureSensorTest.h"
#include "TestTemperatureSensor.h"
#include "TemperatureSensor.h"
#include <cassert>

namespace {
	double abs(double value) { return value > 0 ? value : -value; }
	bool EqualDouble(double lhs, double rhs, double accurate) { return abs(lhs - rhs) < accurate; }
}

void TestTemperatureSensorTest::excute()
{
	readRandomValue(-10,10,10);
	readRandomValue(-1, 0, 3);
	readRandomValue(0, 1, 3);
	readRandomValue(3, 3, 5);
	readRandomValue(-4, -4, 5);
	readPresetValue(std::vector<double>({ 1, 2, 3, 4}), 8);
	readPresetValue(std::vector<double>({ 1, 2, 1, 4, 5, -5, -7, 1, 9}), 8);
}

void TestTemperatureSensorTest::readRandomValue(int minValue, int maxValue, int numberOfCallOfFunction)
{
	const double deltaEqual = 0.01;
	TemperatureSensor* ts = new TestTemperatureSensor(minValue, maxValue);
	for (int i = 0; i < numberOfCallOfFunction; i++)
	{
		double ReadingTemperature = ts->read();
		assert(ReadingTemperature > minValue - deltaEqual
			&& ReadingTemperature < maxValue + deltaEqual);
	}
	delete ts;
}

void TestTemperatureSensorTest::readPresetValue(const std::vector<double>& temperatureValues, int numberOfCallOfFunction)
{
	const double deltaEqual = 0.01;
	TemperatureSensor* ts = new TestTemperatureSensor(temperatureValues);
	for (int i = 0; i < numberOfCallOfFunction; i++)
	{
		double ReadingTemperature = ts->read();
		assert(EqualDouble(ReadingTemperature,temperatureValues.at(i%temperatureValues.size()),0.01));
	}
	delete ts;
}
