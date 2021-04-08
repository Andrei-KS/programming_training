#ifndef __TESTBAROMETRICPRESSURESENSOR_H__
#define __TESTBAROMETRICPRESSURESENSOR_H__

#include "BarometricPressureSensor.h"
#include <vector>

/**
* Description of Test class BarometricPressureSensor
*
* This class is Test Implementation of barometric pressure sensor to check
* correct work of program`s functions
*
* @see BarometricPressureSensor
*/
class TestBarometricPressureSensor : public BarometricPressureSensor
{
public:
	/**
	* possible options for the test BarometricPressureSensor
	*/
	enum class TypeReadTestBarometricPressureSensor
	{
		Random = 0,
		PresetValues = 1
	};

	/**
	* Ñonstructor for creating a new Test BarometricPressureSensor with generator random pressure value from minValue to maxValue
	* @param minValue - minimum available value pressure that will return from calling function read
	* @param maxValue - maximum available value pressure that will return from calling function read
	*/
	TestBarometricPressureSensor(int minValue, int maxValue);

	/**
	* Ñonstructor for creating a new BarometricPressureSensor with preset pressure values
	* @param temperatureValues - array(vector) pressure values that will cycle return from calling function read
	*/
	TestBarometricPressureSensor(const std::vector<double>& pressureValues);

	/**
	* Destructor for created the BarometricPressureSensor
	*/
	virtual ~TestBarometricPressureSensor();

	/**
	* Function return test value temperature for simulation work barometric pressure sensor
	* @return temperature values
	*/
	virtual double read() override;

private:
	/**
	* Field is Type Reading Test Barometric Pressure Sensor
	*/
	TypeReadTestBarometricPressureSensor itsTypeReadTest;

	/**
	* field of given values in the process of creating an object
	*/
	std::vector<double> itsValues;

	/**
	* Service variable for the preset
	* @see TestBarometricPressureSensor.read()
	*/
	int itsIndex;
};

#endif // !__TESTBAROMETRICPRESSURESENSOR_H__