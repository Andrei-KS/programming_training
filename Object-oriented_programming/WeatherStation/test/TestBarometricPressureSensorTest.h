#ifndef __TESTBAROMETRICPRESSURESENSORTEST_H__
#define _TESTBAROMETRICPRESSURESENSORTEST_H__

#include <vector>

/**
* Description of class TestBarometricPressureSensorTest
*
* This class check function class TestBarometricPressureSensor
*
* @see BarometricPressureSensor, TestBarometricPressureSensor
*/
class TestBarometricPressureSensorTest
{
public:
	/**
	* function to run all tests
	*/
	void excute();

protected:
	/**
	* function check correct work function of read random pressure value
	* @param minValue - minimum available value pressure that will return from calling function read
	* @param maxValue - maximum available value pressure that will return from calling function read
	* @param numberOfCallOfFunction - number of readings from the sensor
	* @see BarometricPressureSensor, TestBarometricPressureSensor
	*/
	void readRandomValue(int minValue, int maxValue, int numberOfCallOfFunction);

	/**
	* function check correct work function of read preset pressure values
	* @param temperatureValues - array(vector) pressure values that will cycle return from calling function read
	* @param numberOfCallOfFunction - number of readings from the sensor
	* @see BarometricPressureSensor, TestBarometricPressureSensor
	*/
	void readPresetValue(const std::vector<double>& pressureValues, int numberOfCallOfFunction);

	/**
	* Function check correct work constructor with preset values pressures content zero size vector
	* @see TestBarometricPressureSensor
	*/
	void creatTestBarometricPressureSensorWithZeroVector();

	/**
	* function check correct work function of read preset pressure values
	* @param temperatureValues - array(vector) pressure values that will cycle return from calling function read
	* @param numberOfCallOfFunction - number of readings from the sensor
	* @see BarometricPressureSensor, TestBarometricPressureSensor, AlarmClock, AlramListener
	*/
	void AlarmClockReadPresetValueBarometricPressureSensor(const std::vector<double>& pressureValues, int numberOfCallOfFunction);

	/**
	* Function check correct work constructor with not set AlramClock (AlramClock is nullptr)
	*/
	void creatTestBarometricPressureSensorWithNullAlramClock();

	/**
	* Function check correct work constructor with not set TemperatureSensorImp (TemperatureSensorImp is nullptr)
	*/
	void creatTestTemperatureSensorWithNullTemperatureSensorImp();
};

#endif // !_TESTBAROMETRICPRESSURESENSORTEST_H__