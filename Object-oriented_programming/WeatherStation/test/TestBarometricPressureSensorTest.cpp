

#include "TestBarometricPressureSensorTest.h"
#include "TestBarometricPressureSensor.h"
#include "BarometricPressureSensor.h"
#include <cassert>

namespace {
	double abs(double value) { return value > 0 ? value : -value; }
	bool EqualDouble(double lhs, double rhs, double accurate) { return abs(lhs - rhs) < accurate; }
}

void TestBarometricPressureSensorTest::excute()
{
	readRandomValue(-10, 10, 10);
	readRandomValue(-1, 0, 3);
	readRandomValue(0, 1, 3);
	readRandomValue(3, 3, 5);
	readRandomValue(-4, -4, 5);
	readPresetValue(std::vector<double>({ 1, 2, 3, 4 }), 8);
	readPresetValue(std::vector<double>({ 1, 2, 1, 4, 5, -5, -7, 1, 9 }), 8);
	creatTestBarometricPressureSensorWithZeroVector();
}

void TestBarometricPressureSensorTest::readRandomValue(int minValue, int maxValue, int numberOfCallOfFunction)
{
	const double deltaEqual = 0.01;
	BarometricPressureSensor* bps = new TestBarometricPressureSensor(minValue, maxValue);
	for (int i = 0; i < numberOfCallOfFunction; i++)
	{
		double ReadingPressure = bps->read();
		assert(ReadingPressure > minValue - deltaEqual
			&& ReadingPressure < maxValue + deltaEqual);
	}
	delete bps;
}

void TestBarometricPressureSensorTest::readPresetValue(const std::vector<double>& pressureValues, int numberOfCallOfFunction)
{
	const double deltaEqual = 0.01;
	BarometricPressureSensor* bps = new TestBarometricPressureSensor(pressureValues);
	for (int i = 0; i < numberOfCallOfFunction; i++)
	{
		double ReadingPressure = bps->read();
		assert(EqualDouble(ReadingPressure, pressureValues.at(i % pressureValues.size()), 0.01));
	}
	delete bps;
}

void TestBarometricPressureSensorTest::creatTestBarometricPressureSensorWithZeroVector()
{
	bool isGetThowCase = false;
	try
	{
		BarometricPressureSensor* bps = new TestBarometricPressureSensor(std::vector<double>());
	}
	catch (...)
	{
		isGetThowCase = true;
	}
	assert(isGetThowCase == true);
}

