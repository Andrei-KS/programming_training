#ifndef __ALARMLISTENER_H__
#define __ALARMLISTENER_H__

/**
* Description of class AlarmListener
*
* This interface contain a polymorphic wakeup function that called when AlarmClock make to notification about finished time`s interval
*
* @see pattern Listener, AlarmClock
*/
class AlarmListener
{
public:
	/**
	* Destructor for created the AlarmListener
	*/
	virtual ~AlarmListener();

	/**
	* This function is activated when AlarmClock make to notification about finished time`s interval
	*/
	virtual void wakeup() = 0;
};

#endif // !__ALARMLISTENER_H__