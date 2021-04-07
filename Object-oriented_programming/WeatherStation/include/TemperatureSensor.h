#ifndef __TEMPERATURESENSOR_H__
#define __TEMPERATURESENSOR_H__

#include "Observable.h"

/**
* Description of abstract class TemperatureSensor
* 
* TemperatureSensors is base class contained polymorph function of read.
* 
*/
class TemperatureSensor : public Observable
{

public:
	/**
	* �onstructor for creating a new defualt TemperatureSensor
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