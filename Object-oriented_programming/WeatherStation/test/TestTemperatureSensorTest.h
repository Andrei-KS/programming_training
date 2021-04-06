#ifndef __TESTTEMPERATURESENSORTEST_H__
#define __TESTTEMPERATURESENSORTEST_H__

#include <vector>

/**
* Description of class TestTemperatureSensorTest
*
* This class check function class TestTemperatureSensor
*
* @see TemperatureSensor, TestTemperatureSensor
*/
class TestTemperatureSensorTest
{
public:
	/**
	* function to run all tests
	*/
	void excute();

protected:
	/**
	* function check correct work function of read random temperature value
	* @param minValue - minimum available value temperature that will return from calling function read
	* @param maxValue - maximum available value temperature that will return from calling function read
	* @param numberOfCallOfFunction - number of readings from the sensor  
	*/
	void readRandomValue(int minValue, int maxValue, int numberOfCallOfFunction);

	/**
	* function check correct work function of read preset temperature values
	* @param temperatureValues - array(vector) temperature values that will cycle return from calling function read
	* @param numberOfCallOfFunction - number of readings from the sensor
	*/
	void readPresetValue(const std::vector<double>& temperatureValues, int numberOfCallOfFunction);
};

#endif // !__TESTTEMPERATURESENSORTEST_H__
