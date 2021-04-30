

#include "TestTemperatureSensorTest.h"
#include "TestTemperatureSensor.h"
#include "TemperatureSensor.h"
#include <cassert>
#include "myLibMath.h"
#include "AlarmClock.h"
#include "TestMonitoringScreenImplementation.h"

void TestTemperatureSensorTest::excute()
{
	creatTestTemperatureSensorWithZeroVector();
	creatTestTemperatureSensorWithNullTemperatureSensorImp();
	creatTestTemperatureSensorWithNullAlramClock();

	readRandomValue(-10,10,10);
	readRandomValue(-1, 0, 3);
	readRandomValue(0, 1, 3);
	readRandomValue(3, 3, 5);
	readRandomValue(-4, -4, 5);
	readPresetValue(std::vector<double>({ 1, 2, 3, 4}), 8);
	readPresetValue(std::vector<double>({ 1, 2, 1, 4, 5, -5, -7, 1, 9}), 8);
	AlarmClockReadTemperatureSensor(std::vector<double>({ 1, 2, 1, 4, 5, -5, -7, 1, 9 }), 8);
}

void TestTemperatureSensorTest::readRandomValue(int minValue, int maxValue, int numberOfCallOfFunction)
{
	const double accuracy = 0.001;
	AlarmClock ac;
	TemperatureSensor* ts = new TemperatureSensor(&ac, new TestTemperatureSensor(minValue, maxValue));
	for (int i = 0; i < numberOfCallOfFunction; i++)
	{
		double ReadingTemperature = ts->read();
		assert(myLibMath::GreaterOrEqualDouble(ReadingTemperature,minValue, accuracy)
			&& myLibMath::LessOrEqualDouble(ReadingTemperature,maxValue, accuracy));
	}
	delete ts;
}

void TestTemperatureSensorTest::readPresetValue(const std::vector<double>& temperatureValues, int numberOfCallOfFunction)
{
	const double accuracy = 0.001;
	AlarmClock ac;
	TemperatureSensor* ts = new TemperatureSensor(&ac, new TestTemperatureSensor(temperatureValues));
	for (int i = 0; i < numberOfCallOfFunction; i++)
	{
		double ReadingTemperature = ts->read();
		assert(myLibMath::EqualDouble(ReadingTemperature,temperatureValues.at(i%temperatureValues.size()), accuracy));
	}
	delete ts;
}

void TestTemperatureSensorTest::creatTestTemperatureSensorWithZeroVector()
{
	bool isGetThowCase = false;
	AlarmClock ac;
	try
	{
		TestTemperatureSensor* tts = new TestTemperatureSensor(std::vector<double>());
	}
	catch (...)
	{
		isGetThowCase = true;
	}
	assert(isGetThowCase == true);
}

void TestTemperatureSensorTest::AlarmClockReadTemperatureSensor(const std::vector<double>& temperatureValues, int numberOfCallOfFunction)
{
	const double accuracy = 0.001;
	AlarmClock* ac = new AlarmClock();
	TemperatureSensor* ts = new TemperatureSensor(ac, new TestTemperatureSensor(temperatureValues));
	TestMonitoringScreenImplementation msi(ts,nullptr,nullptr);
	for (int i = 0; i < numberOfCallOfFunction; i++)
	{
		ac->wakeupAll();
		assert(myLibMath::EqualDouble(msi.getTemp(), temperatureValues.at(i % temperatureValues.size()), accuracy));
	}
	delete ac;
	delete ts;
}

void TestTemperatureSensorTest::creatTestTemperatureSensorWithNullAlramClock()
{
	bool isGetThowCase = false;
	try
	{
		TemperatureSensor* ts = new TemperatureSensor(nullptr, new TestTemperatureSensor(std::vector<double>({ 1, 2, 3, 4 })));
	}
	catch (...)
	{
		isGetThowCase = true;
	}
	assert(isGetThowCase == true);
}

void TestTemperatureSensorTest::creatTestTemperatureSensorWithNullTemperatureSensorImp()
{
	bool isGetThowCase = false;
	AlarmClock ac;
	try
	{
		TemperatureSensor* ts = new TemperatureSensor(&ac, nullptr);
	}
	catch (...)
	{
		isGetThowCase = true;
	}
	assert(isGetThowCase == true);
}
