#ifndef __BAROMETRICPRESSURESENSOR_H__
#define __BAROMETRICPRESSURESENSOR_H__

#include "Observable.h"
/**
* Description of abstract class BarometricPressureSensor
*
* BarometricPressureSensor is base class giving an interface to work with a barometric pressure sensor.
* For this class, it is possible to register observers to track pressure changes
*
* @see Observable
*/
class BarometricPressureSensor : public Observable
{
public:
	/**
	* Ñonstructor for creating a new defualt BarometricPressureSensor
	*/
	BarometricPressureSensor();

	/**
	* Destructor for created the BarometricPressureSensor
	*/
	virtual ~BarometricPressureSensor();

	/*Function takes barometric pressure readings from the sensor
	* @return barometric pressure values
	*/
	virtual double read() = 0;
};

#endif // !__BAROMETRICPRESSURESENSOR_H__