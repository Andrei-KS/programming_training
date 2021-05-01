

#include "TestBarometricPressureSensorTest.h"
#include "TestBarometricPressureSensor.h"
#include "BarometricPressureSensor.h"
#include <cassert>
#include "myLibMath.h"
#include "AlarmClock.h"
#include "TestMonitoringScreenImplementation.h"

myUTest* myUTest::Utest = new TestBarometricPressureSensorTest();

void TestBarometricPressureSensorTest::excute()
{
	creatTestBarometricPressureSensorWithZeroVector();
	creatTestBarometricPressureSensorWithNullAlramClock();
	creatTestTemperatureSensorWithNullTemperatureSensorImp();
	readRandomValue(-10, 10, 10);
	readRandomValue(-1, 0, 3);
	readRandomValue(0, 1, 3);
	readRandomValue(3, 3, 5);
	readRandomValue(-4, -4, 5);
	readPresetValue(std::vector<double>({ 1, 2, 3, 4 }), 8);
	readPresetValue(std::vector<double>({ 1, 2, 1, 4, 5, -5, -7, 1, 9 }), 8);
	AlarmClockReadPresetValueBarometricPressureSensor(std::vector<double>({ 1, 2, 1, 4, 5, -5, -7, 1, 9 }), 8);
}

void TestBarometricPressureSensorTest::readRandomValue(int minValue, int maxValue, int numberOfCallOfFunction)
{
	const double accuracy = 0.001;
	AlarmClock ac;
	BarometricPressureSensor* bps = new BarometricPressureSensor(&ac, new TestBarometricPressureSensor(minValue, maxValue));
	for (int i = 0; i < numberOfCallOfFunction; i++)
	{
		double ReadingPressure = bps->read();
		assert(myLibMath::GreaterOrEqualDouble(ReadingPressure, minValue, accuracy)
			&& myLibMath::LessOrEqualDouble(ReadingPressure, maxValue, accuracy));
	}
	delete bps;
}

void TestBarometricPressureSensorTest::readPresetValue(const std::vector<double>& pressureValues, int numberOfCallOfFunction)
{
	const double accuracy = 0.001;
	AlarmClock ac;
	BarometricPressureSensor* bps = new BarometricPressureSensor(&ac, new TestBarometricPressureSensor(pressureValues));
	for (int i = 0; i < numberOfCallOfFunction; i++)
	{
		double ReadingPressure = bps->read();
		assert(myLibMath::EqualDouble(ReadingPressure, pressureValues.at(i % pressureValues.size()), accuracy));
	}
	delete bps;
}

void TestBarometricPressureSensorTest::creatTestBarometricPressureSensorWithZeroVector()
{
	bool isGetThowCase = false;
	try
	{
		BarometricPressureSensorImp* bps = new TestBarometricPressureSensor(std::vector<double>());
	}
	catch (...)
	{
		isGetThowCase = true;
	}
	assert(isGetThowCase == true);
}

void TestBarometricPressureSensorTest::AlarmClockReadPresetValueBarometricPressureSensor(const std::vector<double>& pressureValues, int numberOfCallOfFunction)
{
	const double accuracy = 0.001;
	AlarmClock* ac = new AlarmClock();
	BarometricPressureSensor* bps = new BarometricPressureSensor(ac, new TestBarometricPressureSensor(pressureValues));
	TestMonitoringScreenImplementation msi(nullptr, bps, nullptr);
	for (int i = 0; i < numberOfCallOfFunction; i++)
	{
		ac->wakeupAll();
		assert(myLibMath::EqualDouble(msi.getPressure(), pressureValues.at(i % pressureValues.size()), accuracy));
	}
	delete ac;
	delete bps;
}

void TestBarometricPressureSensorTest::creatTestBarometricPressureSensorWithNullAlramClock()
{
	bool isGetThowCase = false;
	try
	{
		BarometricPressureSensor* bps = new BarometricPressureSensor(nullptr, new TestBarometricPressureSensor(std::vector<double>({ 1, 2, 3, 4 })));
	}
	catch(...)
	{
		isGetThowCase = true;
	}
	assert(isGetThowCase == true);
}

void TestBarometricPressureSensorTest::creatTestTemperatureSensorWithNullTemperatureSensorImp()
{
	bool isGetThowCase = false;
	AlarmClock ac;
	try
	{
		BarometricPressureSensor* bps = new BarometricPressureSensor(&ac, nullptr);
	}
	catch (...)
	{
		isGetThowCase = true;
	}
	assert(isGetThowCase == true);
}

