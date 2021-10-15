#ifndef __BAROMETRICPRESSURESENSOR_H__
#define __BAROMETRICPRESSURESENSOR_H__

#include "Observable.h"
#include "AlarmClock.h"
#include "AlarmListener.h"
#include "StationToolkit.h"

class BarometricPressureSensorImp;

/**
* Description of abstract class BarometricPressureSensor
*
* BarometricPressureSensor is base class giving an interface to work with a barometric pressure sensor.
* For this class, it is possible to register observers to track pressure changes and bind class implementation
*
* @see Observable, pattern Bridge, BarometricPressureSensorImp
*/
class BarometricPressureSensor : public Observable
{
public:
	/**
	* Ñonstructor for creating a new BarometricPressureSensor
	* @param AClock - pointer to the alarm clocker are associated with this temperature sensor
	* @param st - a pointer to the StationToolkit that is responsible for creating the implementation of this BarometricPressureSensor
	*/
	BarometricPressureSensor(AlarmClock* AClock, StationToolkit* st);

	/**
	* Destructor for created the BarometricPressureSensor
	*/
	virtual ~BarometricPressureSensor();

	/*Function takes barometric pressure readings from the sensor
	* @return barometric pressure values
	*/
	double read();

protected:
	/**
	* Function check new reading value. 
	*/
	void check();

	/**
	* Anonymous listener connects the barometric pressure sensor to the AlarmClock. After the expiration of the time in the alarm clock, the function of checking the associated barometric pressure sensor class will be called
	* @see AlarmClock
	*/
	class : public AlarmListener
	{
	public:
		/**
		* This function is activated when AlarmClock make to notification about finished time`s interval
		*/
		virtual void wakeup()
		{
			if (itsBarometricPressureSensor != nullptr)
			{
				itsBarometricPressureSensor->check();
			}
		}
		/**
		* The field contains pointer to barometric pressure sensor for which called check function
		*/
		BarometricPressureSensor* itsBarometricPressureSensor = nullptr;
	} itsListener;

private:
	/**
	* Field contains implementation of barometric pressure sensor bonded to this object
	*/
	BarometricPressureSensorImp* itsBarometricPressureSensorImp;
};

#endif // !__BAROMETRICPRESSURESENSOR_H__