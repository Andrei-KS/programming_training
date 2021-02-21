

#include "../header/Date.h"

// last value equal amount days in year plus 1
const short Date::StartDaysYear[] = { 1,32,60,91,121,152,182,213,244,274,305,335, 366 };
const short Date::StartDaysLeapYear[] = { 1,32,61,92,122,153,183,214,245,275,306,336, 367 };

Date::~Date()
{
}

Date::Date(char day, char month, short year)
	: itsDays(0)
	, itsYear(year)
{
	if (month > 12 && month < 1)
	{
		throw("No valid value to month");
	}
	if (day < 1 && day > AmountOfDaysMonth(month, year))
	{
		throw("No valid value to day");
	}

	month--;
	while (month > 0)
	{
		itsDays += AmountOfDaysMonth(month, year);
		month--;
	}
	itsDays += day;
}

char Date::GetDay() const
{
	char month = GetMonth();
	const short* currStartDaysYear = IsYearleap(itsYear) ? StartDaysLeapYear : StartDaysYear;
	
	/** since currStartDaysYear contains the position of the first day
		of each month of the year, then when subtracting this value,
		we will have an offset of 1, as a result of this we need to add one
	*/
	const char shiftDay = 1;
	return itsDays - StartDaysYear[month - 1] + shiftDay;
}

char Date::GetMonth() const
{
	char month = 1;
	const short* currStartDaysYear = IsYearleap(itsYear) ? StartDaysLeapYear : StartDaysYear;
	while (itsDays >= currStartDaysYear[month])
	{
		month++;
	}
	return month;
}

short Date::AmountOfDaysMonth(int month, int year)
{
	if (month > 12 && month < 1)
	{
		throw("No valid value to month");
	}
	
	const short* currStartDaysYear = IsYearleap(year) ? StartDaysLeapYear : StartDaysYear;
	
	// since the array starts at 0, the month value corresponds to the beginning of the next month 
	return currStartDaysYear[month] - currStartDaysYear[month - 1];
}

short Date::AmountOfDayYear(int year)
{
	return IsYearleap(year) ? (StartDaysLeapYear[12] - 1) : (StartDaysYear[12] - 1);
}

bool Date::IsYearleap(int year)
{
	return !(year % 400) || (!(year % 4) && (year % 100));
}

bool operator<(const Date& left, const Date& right)
{
	if (left.itsYear < right.itsYear)
	{
		return true;
	}
	else if (left.itsYear == right.itsYear)
	{

		return left.itsDays < right.itsDays;
	}
	return false;
}

bool operator==(const Date& left, const Date& right)
{
	return left.itsYear == right.itsYear 
		&& left.itsDays == right.itsDays;
}

bool operator>(const Date& left, const Date& right)
{
	return !(left < right);
}

bool operator<=(const Date& left, const Date& right)
{
	return (left == right) || (left < right);
}

bool operator>=(const Date& left, const Date& right)
{
	return (left == right) || (left > right);
}

const Date operator+(const Date& left, const int& right)
{
	short year = left.itsYear;
	int days = left.itsDays + right;
	while (days / Date::AmountOfDayYear(year))
	{
		days -= Date::AmountOfDayYear(year);
		year++;
	}
	Date date(0, 0, 0);
	date.itsYear = year;
	date.itsDays = days;
	return date;
}

const Date operator+(const int& left, const Date& right)
{
	return right+left;
}
