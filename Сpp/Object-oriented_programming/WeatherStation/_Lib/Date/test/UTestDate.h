#ifndef __UTESTDATE_H__
#define __UTESTDATE_H__

#include "myUTest.h"

class UTestDate : public myUTest
{
public:
	/**
	* function to run all tests
	*/
	virtual void excute() override;

protected:
	void TestAmountOfDaysMonth();
	void TestAmountOfDaysYear();
	void TestOrderOfDate();
	void TestAddDays();
	void TestGetDate();
	void TestSubtractionDays();
	void TestGetDayOfWeek();
};

#endif // !__UTESTDATE_H__