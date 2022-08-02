#ifndef __CLOCKLISTNER_H__
#define __CLOCKLISTNER_H__

/**
* Description of class ClockListner
* An object interface that listens to the timing 
* @see pattern Listener, AlarmClockImp
*/
class ClockListner
{
public:
	/**
	* A function that updates the this object
	*/
	virtual void tic() = 0;;
};

#endif // !__CLOCKLISTNER_H__