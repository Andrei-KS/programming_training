

#include "TestBarometricPressureSensorTest.h"
#include "TestBarometricPressureSensor.h"
#include "BarometricPressureSensor.h"
#include <cassert>
#include "myLibMath.h"
#include "AlarmClock.h"
#include "TestMonitoringScreenImplementation.h"
#include "StationToolkit.h"

myUTest* myUTest::Utest = new TestBarometricPressureSensorTest();

namespace {
	class TStationToolkit : public StationToolkit
	{
	public:
		TStationToolkit(int minValue, int maxValue)
			: itsValues(std::vector<double>(2, 0))
			, itsTypeReadTest(TestBarometricPressureSensor::TypeReadTestBarometricPressureSensor::Random)
		{
			itsValues.at(0) = minValue;
			itsValues.at(1) = maxValue;
		}

		TStationToolkit(const std::vector<double>& pressureValues)
			: itsValues(pressureValues)
			, itsTypeReadTest(TestBarometricPressureSensor::TypeReadTestBarometricPressureSensor::PresetValues)
		{
		}

		virtual TemperatureSensorImp* makeTemperature() override { return nullptr; }
		virtual BarometricPressureSensorImp* makeBarometricPressure() override
		{
			if (itsTypeReadTest == TestBarometricPressureSensor::TypeReadTestBarometricPressureSensor::Random)
			{
				return new TestBarometricPressureSensor(static_cast<int>(itsValues.at(0)), static_cast<int>(itsValues.at(1)));
			}
			else
			{
				return new TestBarometricPressureSensor(itsValues);
			}
		}

	private:
		std::vector<double> itsValues;
		TestBarometricPressureSensor::TypeReadTestBarometricPressureSensor itsTypeReadTest;
	};
}

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
	TStationToolkit tst(minValue, maxValue);
	BarometricPressureSensor* bps = new BarometricPressureSensor(&ac, &tst);
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
	TStationToolkit tst(pressureValues);
	BarometricPressureSensor* bps = new BarometricPressureSensor(&ac, &tst);
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
	TStationToolkit tst(pressureValues);
	BarometricPressureSensor* bps = new BarometricPressureSensor(ac, &tst);
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
		TStationToolkit tst(std::vector<double>({ 1, 2, 3, 4 }));
		BarometricPressureSensor* bps = new BarometricPressureSensor(nullptr, &tst);
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

