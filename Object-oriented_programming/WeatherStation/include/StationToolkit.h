#ifndef __STATIONTOOLKIT_H__
#define __STATIONTOOLKIT_H__

class TemperatureSensorImp;
class BarometricPressureSensorImp;
/**
* An interface class representing methods for instantiating
* classes from an API interface
* 
* @see pattern Factory
*/
class StationToolkit
{
public:
	/**
	* creates a temperature sensor implementation
	* @return pointer to the created temperature sensor
	*/
	virtual TemperatureSensorImp* makeTemperature() = 0;

	/**
	* creates a barometric pressure sensor implementation
	* @return pointer to the created barometric pressure sensor
	*/
	virtual BarometricPressureSensorImp* makeBarometricPressure() = 0;
};

#endif // !__STATIONTOOLKIT_H__