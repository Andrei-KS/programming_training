#ifndef __TEMPERATURESENSOR_H__
#define __TEMPERATURESENSOR_H__

#include "Observable.h"

/**
* Description of abstract class TemperatureSensor
* 
* TemperatureSensors is base class giving an interface to work with a temperature sensor.
* For this class, it is possible to register observers to track temperature changes
* 
* @see Observable
*/
class TemperatureSensor : public Observable
{

public:
	/**
	* Ñonstructor for creating a new defualt TemperatureSensor
	*/
	TemperatureSensor();
	
	/**
	* Destructor for created the TemperatureSensor
	*/
	virtual ~TemperatureSensor();

	/**
	* Function takes temperature readings from the sensor
	* @return temperature values 
	*/
	virtual double read() = 0;
};

#endif // !__TEMPERATURESENSOR_H__