#ifndef __TESTTEMPERATURESENSOR_H__
#define __TESTTEMPERATURESENSOR_H__

#include "TemperatureSensor.h"
#include <vector>

/**
* Description of Test class TemperatureSensor
* 
* This class is Test Implementation of Temperature Sensor to check
* correct work of program`s functions
* 
* @see TemperatureSensor
*/
class TestTemperatureSensor : public TemperatureSensor
{
public:
	/**
	* possible options for the test Temperatur sensor 
	*/
	enum class TypeReadTestTemperatureSensor
	{
		Random = 0,
		PresetValues = 1
	};

	/**
	* Ñonstructor for creating a new Test Temperature Sensor with generator random temperature value from minValue to maxValue
	* @param minValue - minimum available value temperature that will return from calling function read
	* @param maxValue - maximum available value temperature that will return from calling function read
	*/
	TestTemperatureSensor(int minValue, int maxValue);

	/**
	* Ñonstructor for creating a new TestTemperatureSensor with preset temperature value
	* @param temperatureValues - array(vector) temperature values that will cycle return from calling function read
	*/
	TestTemperatureSensor(const std::vector<double>& temperatureValues);

	/**
	* Destructor for created the TestTemperatureSensor
	*/
	virtual ~TestTemperatureSensor();

	/**
	* Function return test value temperature for simulation work temperature sensor
	* @return temperature values
	*/
	virtual double read() override;

private:
	/**
	* Field is Type Reading Test Temperature Sensor  
	*/
	TypeReadTestTemperatureSensor itsTypeReadTest;

	/**
	* field of given values in the process of creating an object
	*/
	std::vector<double> itsValues;

	/**
	* Service variable for the preset
	* @see TestTemperatureSensor.read()
	*/
	int itsIndex;
};

#endif // !__TESTTEMPERATURESENSOR_H__