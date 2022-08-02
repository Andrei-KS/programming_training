#ifndef __TEMPERATUREHILO_H__
#define __TEMPERATUREHILO_H__

#include "AlarmListener.h"
#include "Observer.h"
#include "TemperatureSensor.h"
#include "HiLoData.h"

/**
* class responsible for collecting data from sensors after a set time interval
* or when updating data on the sensor and then transferring data
* to the HiLoData handler
* 
* @see Observer, AlarmListener, TemperatureSensor, AlarmClock, TemperatureHiLoData
*/
class TemperatureHiLo : public Observer
{
public:
	/**
	* Constructor for creating a new TemperatureHiLo associated with the TemperatureSensor
	* @param AClock - pointer to the alarm clocker are associated with this TemperatureHiLo
	* @param ts - TemperatureSensor which will be associated with this object
	* @see AlarmClock, TemperatureSensor
	*/
	TemperatureHiLo(AlarmClock* AClock, TemperatureSensor* ts, HiLoData* hld);

	/**
	* When the temperature is read on the sensor, this will be called 
	* @param value - the value obtained from the observed subject
	* @see Observable
	*/
	virtual void update(double value) override;

protected:
	/**
	* Anonymous listener connects the TemperatureHiLo to the AlarmClock.
	* After the expiration of the time in the alarm clock, the function of
	* checking the associated TemperatureHiLo class will be called
	* @see AlarmClock
	*/
	class : public AlarmListener
	{
	public:
		/**
		* This function is activated when AlarmClock make to notification about finished time`s interval
		*/
		virtual void wakeup() override
		{
			double currentTemperature = itsTemperatureSensor->read();
			itsTemperatureHiLo->itsCurrentTime = 0;
			itsTemperatureHiLo->itsHiLoDate->newDay(currentTemperature, itsTemperatureHiLo->itsCurrentTime);
		}

		/** TemperatureHiLo which will be associated with this object */
		TemperatureHiLo* itsTemperatureHiLo;

		/** TemperatureSensor which will be associated with itsTemperatureHiLo */
		TemperatureSensor* itsTemperatureSensor;

	} itsListener;

	/**
	* Pointer to the algorithm responsible for determining the highest and lowest values
	* @see HiLoData
	*/
	HiLoData* itsHiLoDate;

	/** current time*/
	long itsCurrentTime;
};

#endif // !__TEMPERATUREHILO_H__