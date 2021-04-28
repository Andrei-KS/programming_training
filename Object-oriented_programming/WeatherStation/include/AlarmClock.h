#ifndef __ALARMCLOCK_H__
#define __ALARMCLOCK_H__

#include <vector>
#include "AlarmListener.h"

/**
* Description of class AlarmClock
*
* AlarmClock let to register Listeners with given interval invocations.
*
* @see pattern Listener, AlarmListener
*/
class AlarmClock
{
public:
	/**
	* Constructor for creating a new defualt AlarmClock
	*/
	AlarmClock();

	/**
	* Destructor for created the AlarmClock. Since this object does not own listeners, it will not delete them 
	*/
	~AlarmClock();

	/**
	* AlarmClock registration function
	* @param interval - how often the listener will notify, the value is set in milliseconds
	* @param AListner - registered AlarmListner 
	*/
	void wakeEvery(int interval, AlarmListener* AListner);

	/**
	* wakups all registered listeners
	*/
	void wakeupAll() const;


private:
	/**
	* the field containing all registered alarm listners
	*/
	std::vector<AlarmListener*> itsAlarmListners;
};

#endif // !__ALARMCLOCK_H__