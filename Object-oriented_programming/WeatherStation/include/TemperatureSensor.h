#ifndef __TEMPERATURESENSOR_H__
#define __TEMPERATURESENSOR_H__

#include "Observable.h"
#include "AlarmClock.h"
#include "AlarmListener.h"

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
	* Ñonstructor for creating a new TemperatureSensor
	* @param AClock - pointer to the alarm clocker are associated with this temperature sensor
	* @see AlarmClock
	*/
	TemperatureSensor(AlarmClock* AClock);
	
	/**
	* Destructor for created the TemperatureSensor
	*/
	virtual ~TemperatureSensor();
	
	/**
	* Function takes temperature readings from the sensor
	* @return temperature values
	*/
	virtual double read() = 0;

protected:
	/**
	* Function check new reading value. if new value is not equal last value, this function notify registered observers about changed value
	*/
	void check();

	/**
	* The field contains last reading value
	*/
	double itsLastReading;

	/**
	* Anonymous listener connects the temperature sensor to the AlarmClock. After the expiration of the time in the alarm clock, the function of checking the associated temperature sensor class will be called  
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
			if (itsTemperatureSensor != nullptr)
			{
				itsTemperatureSensor->check();
			}
		}
		/**
		* The field contains pointer to Temperature Sensor for which called check function
		*/
		TemperatureSensor* itsTemperatureSensor = nullptr;
	} itsListener;
};

#endif // !__TEMPERATURESENSOR_H__