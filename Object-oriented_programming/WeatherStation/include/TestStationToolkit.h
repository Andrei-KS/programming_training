#ifndef __TESTSTATIONTOOLKIT_H__
#define __TESTSTATIONTOOLKIT_H__

#include "StationToolkit.h"
#include "TestTemperatureSensor.h"
#include "TestBarometricPressureSensor.h"

/**
* Overridden  class StationToolkit that creates a test temperature sensor and a test barometric pressure sensor 
*/
class TestStationToolkit : public StationToolkit
{
public:
	/**
	* creates a test temperature sensor implementation with random generting value from -35 to 35
	* @return pointer to the created temperature sensor
	*/
	virtual TemperatureSensorImp* makeTemperature() override;

	/**
	* creates a barometric pressure sensor implementation with random generting value from 360 to 365
	* @return pointer to the created barometric pressure sensor
	*/
	virtual BarometricPressureSensorImp* makeBarometricPressure() override;
};

#endif // !__TESTSTATIONTOOLKIT_H__