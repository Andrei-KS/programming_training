#ifndef __TESTALARMCLOCKIMP_H__
#define __TESTALARMCLOCKIMP_H__

#include "AlarmClockImp.h"
#include <vector>

/**
* Overridden class AlarmClockImp
* @see AlarmClockImp
*/
class TestAlarmClockImp :public AlarmClockImp
{
public:
	/**
	* Ñonstructor for creating a new TestStationToolkit
	*/
	TestAlarmClockImp();

	/**
	* Destructor for created the TestAlarmClockImp
	*/
	virtual ~TestAlarmClockImp();

	/**
	* TestAlarmClockImp registration function
	* @param AListner - registered ClockListner
	*/
	virtual void registerClockListner(ClockListner* al) override;

	/**
	* starts the implementation of the alarm clock
	*/
	void run();

private:
	/** the field containing all registered Clock listners */
	std::vector<ClockListner*> itsClockListners;
};

#endif // !__TESTALARMCLOCKIMP_H__