

#include "DateTest.h"
#include "../header/Date.h"
#include <cassert>

void DateTest::TestAmountOfDaysMonth()
{
	assert(Date::AmountOfDaysMonth(1, 1) == 31);
	assert(Date::AmountOfDaysMonth(2, 1) == 28);
	assert(Date::AmountOfDaysMonth(3, 1) == 31);
	assert(Date::AmountOfDaysMonth(4, 1) == 30);
	assert(Date::AmountOfDaysMonth(5, 1) == 31);
	assert(Date::AmountOfDaysMonth(6, 1) == 30);
	assert(Date::AmountOfDaysMonth(7, 1) == 31);
	assert(Date::AmountOfDaysMonth(8, 1) == 31);
	assert(Date::AmountOfDaysMonth(9, 1) == 30);
	assert(Date::AmountOfDaysMonth(10, 1) == 31);
	assert(Date::AmountOfDaysMonth(11, 1) == 30);
	assert(Date::AmountOfDaysMonth(12, 1) == 31);

	// amount of days in leap and non-leap years
	assert(Date::AmountOfDaysMonth(2, 1) == 28);
	assert(Date::AmountOfDaysMonth(2, 400) == 29);
	assert(Date::AmountOfDaysMonth(2, 100) == 28);
	assert(Date::AmountOfDaysMonth(2, 200) == 28);
	assert(Date::AmountOfDaysMonth(2, 204) == 29);
}

void DateTest::TestAmountOfDaysYear()
{
	// amount of days in leap and non-leap years
	assert(Date::AmountOfDayYear(1) == 365);
	assert(Date::AmountOfDayYear(400) == 366);
	assert(Date::AmountOfDayYear(100) == 365);
	assert(Date::AmountOfDayYear(200) == 365);
	assert(Date::AmountOfDayYear(204) == 366);
}

void DateTest::TestOrderOfDate()
{
	assert(Date(1, 1, 3) == Date(1, 1, 3));
	assert(Date(1, 2, 1) == Date(1, 2, 1));
	assert(Date(2, 1, 1) == Date(2, 1, 1));
	assert(Date(1, 2, 3) == Date(1, 2, 3));

	assert(Date(1, 1, 1) < Date(2, 1, 1));
	assert(Date(1, 1, 1) < Date(1, 2, 1));
	assert(Date(1, 1, 1) < Date(1, 1, 2));

	assert(Date(1, 2, 3) <= Date(1, 2, 3));
	assert(Date(1, 1, 1) <= Date(2, 1, 1));
	assert(Date(1, 1, 1) <= Date(1, 2, 1));
	assert(Date(1, 1, 1) <= Date(1, 1, 2));

	assert(Date(2, 1, 1) > Date(1, 1, 1));
	assert(Date(1, 2, 1) > Date(1, 1, 1));
	assert(Date(1, 1, 2) > Date(1, 1, 1));

	assert(Date(1, 2, 3) == Date(1, 2, 3));
	assert(Date(2, 1, 1) >= Date(1, 1, 1));
	assert(Date(1, 2, 1) >= Date(1, 1, 1));
	assert(Date(1, 1, 2) >= Date(1, 1, 1));
}

void DateTest::TestAddDays()
{
	assert(Date(1, 1, 1) + 1 == Date(2, 1, 1));
	assert(Date(1, 1, 1) + 31 == Date(1, 2, 1));
	assert(Date(1, 1, 1) + 59 == Date(1, 3, 1));
	assert(Date(1, 1, 1) + 100 == Date(11, 4, 1));
	assert(Date(1, 1, 1) + 400 == Date(5, 2, 2));
	assert(Date(1, 1, 1) + 1000 == Date(28, 9, 3));
	assert(Date(1, 1, 1) + 30005 == Date(25, 02, 83));

	assert(1 + Date(1, 1, 1) == Date(2, 1, 1));
	assert(31 + Date(1, 1, 1) == Date(1, 2, 1));
	assert(59 + Date(1, 1, 1) == Date(1, 3, 1));
	assert(100 + Date(1, 1, 1) == Date(11, 4, 1));
	assert(400 + Date(1, 1, 1) == Date(5, 2, 2));
	assert(1000 + Date(1, 1, 1) == Date(28, 9, 3));
	assert(30005 + Date(1, 1, 1) == Date(25, 02, 83));
}

void DateTest::TestGetDate()
{
	assert(Date(11,1,2018).GetDay() == 11);
	assert(Date(11, 1, 2018).GetMonth() == 1);
	assert(Date(11, 1, 2018).GetYear() == 2018);

	assert(Date(29, 2, 2000).GetYear() == 2000);
	assert(Date(29, 2, 2000).GetDay() == 29);
	assert(Date(28, 2, 2001).GetDay() == 28);
}
