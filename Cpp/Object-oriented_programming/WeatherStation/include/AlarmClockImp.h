#ifndef __ALARMCLOCKIMP_H__
#define __ALARMCLOCKIMP_H__

#include "ClockListner.h"

/**
* the class interface associated with the implementation supports the hardware platform
* @see pattern Bridge
*/
class AlarmClockImp
{
public:
	/**
	* Destructor for created the AlarmClockImp. 
	*/
	virtual ~AlarmClockImp();

	/**
	* AlarmClock registration function
	* @param AListner - registered ClockListner
	*/
	virtual void registerClockListner(ClockListner* al) = 0;
};

#endif // !__ALARMCLOCKIMP_H__