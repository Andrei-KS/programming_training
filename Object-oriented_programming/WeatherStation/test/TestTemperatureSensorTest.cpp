

#include "TestTemperatureSensorTest.h"
#include "TestTemperatureSensor.h"
#include "TemperatureSensor.h"
#include <cassert>
#include "myLibMath.h"
#include "AlarmClock.h"
#include "TestMonitoringScreenImplementation.h"
#include "StationToolkit.h"
#include "TestAlarmClockImp.h"
#include "WeatherStation.h"
#include "TestBarometricPressureSensor.h"

myUTest* myUTest::Utest = new TestTemperatureSensorTest();

namespace {
	class TStationToolkit : public StationToolkit
	{
	public:
		TStationToolkit(int minValue, int maxValue)
			: itsValues(std::vector<double>(2, 0))
			, itsTypeReadTest(TestTemperatureSensor::TypeReadTestTemperatureSensor::Random)
		{
			itsValues.at(0) = minValue;
			itsValues.at(1) = maxValue;
		}

		TStationToolkit(const std::vector<double>& temperatureValues)
			: itsValues(temperatureValues)
			, itsTypeReadTest(TestTemperatureSensor::TypeReadTestTemperatureSensor::PresetValues)
		{
		}

		~TStationToolkit()
		{
			delete itsAlarmClockImp;
		}

		virtual TemperatureSensorImp* makeTemperature() override
		{
			if (itsTypeReadTest == TestTemperatureSensor::TypeReadTestTemperatureSensor::Random)
			{
				return new TestTemperatureSensor(static_cast<int>(itsValues.at(0)), static_cast<int>(itsValues.at(1)));
			}
			else
			{
				return new TestTemperatureSensor(itsValues);
			}
		}
		virtual BarometricPressureSensorImp* makeBarometricPressure() override { return new TestBarometricPressureSensor(0,0); }
		virtual AlarmClockImp* getAlarmClock() override
		{
			if (itsAlarmClockImp == nullptr)
			{
				itsAlarmClockImp = new TestAlarmClockImp();
			}
			return itsAlarmClockImp;
		}

	private:
		std::vector<double> itsValues;
		TestTemperatureSensor::TypeReadTestTemperatureSensor itsTypeReadTest;
		AlarmClockImp* itsAlarmClockImp = nullptr;
	};
}

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
	TStationToolkit tst(minValue, maxValue);
	AlarmClock ac(&tst);
	TemperatureSensor* ts = new TemperatureSensor(&ac, &tst);
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
	TStationToolkit tst(temperatureValues);
	AlarmClock ac(&tst);
	TemperatureSensor* ts = new TemperatureSensor(&ac, &tst);
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
	TStationToolkit tst(0, 1);
	AlarmClock ac(&tst);
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
	TStationToolkit tst(temperatureValues);
	WeatherStation ws(&tst);
	TestMonitoringScreenImplementation msi(&ws);
	TestAlarmClockImp* taci = dynamic_cast<TestAlarmClockImp*>(tst.getAlarmClock());
	
	for (int i = 0; i < numberOfCallOfFunction; i++)
	{
		taci->run();
		assert(myLibMath::EqualDouble(msi.getTemp(), temperatureValues.at(i % temperatureValues.size()), accuracy));
	}
}

void TestTemperatureSensorTest::creatTestTemperatureSensorWithNullAlramClock()
{
	bool isGetThowCase = false;
	try
	{
		TStationToolkit tst(std::vector<double>({ 1, 2, 3, 4 }));
		TemperatureSensor* ts = new TemperatureSensor(nullptr, &tst);
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
	TStationToolkit tst(0, 1);
	AlarmClock ac(&tst);
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
