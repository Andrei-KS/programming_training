#ifndef __ALARMCLOCK_H__
#define __ALARMCLOCK_H__

#include <vector>
#include "AlarmListener.h"
#include "StationToolkit.h"
#include "ClockListner.h"

/**
* Description of class AlarmClock
*
* AlarmClock let to register Listeners with given interval invocations.
*
* @see pattern Listener, AlarmListener
*/
class AlarmClock : public ClockListner
{
public:
	/**
	* Constructor for creating a new defualt AlarmClock
	* @param st - a pointer to the StationToolkit that is responsible for creating the implementation of this AlarmClock 
	*/
	AlarmClock(StationToolkit* st);

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

	/**
	* A function that updates the this object 
	* check listeners and if it need wake up then it wake up this listner
	*/
	virtual void tic() override;

private:
	/**
	* the field containing all registered alarm listners
	*/
	std::vector<AlarmListener*> itsAlarmListners;
};

#endif // !__ALARMCLOCK_H__