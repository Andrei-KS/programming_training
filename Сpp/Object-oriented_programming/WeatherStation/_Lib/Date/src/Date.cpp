

#include "Date.h"
#include <ctime>

namespace
{
	// last value equal amount days in year plus 1
	static const short const StartDaysYear[] = { 1,32,60,91,121,152,182,213,244,274,305,335, 366 };
	static const short const StartDaysLeapYear[] = { 1,32,61,92,122,153,183,214,245,275,306,336, 367 };

	static const char FirstDayZeroYear = Date::Saturday;
}


Date::~Date()
{
}

Date::Date()
	: itsDays(0)
	, itsYear(0)
{
	// get time now
	std::time_t t = std::time(0);
	std::tm* now = std::localtime(&t);
	itsYear = now->tm_year + 1900;
	itsDays = (IsYearleap(itsYear) ? StartDaysLeapYear[now->tm_mon] : StartDaysLeapYear[now->tm_mon]) - 1 + now->tm_mday;
}

Date::Date(char day, char month, short year)
	: itsDays(0)
	, itsYear(year)
{
	if (month > 12 || month < 1)
	{
		throw("No valid value to month");
	}
	if (day < 1 || day > AmountOfDaysMonth(month, year))
	{
		throw("No valid value to day");
	}
	if (itsYear < 0)
	{
		throw("undefined behavior, year less zero");
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

char Date::GetDayOfWeek() const
{
	short AmountYearsMultipleOfFour = (itsYear - 1) / 4;
	short AmountYearsMultipleOfOneHundred = (itsYear - 1) / 100;
	short AmountYearsMultipleOfFourHundred = (itsYear - 1) / 400;

	short shift =  itsYear + (AmountYearsMultipleOfFour - AmountYearsMultipleOfOneHundred + AmountYearsMultipleOfFourHundred);
	shift += itsYear?1:0; // Zero year Multiple Of Four Hundred
	shift %= AmountDaysPerWeek;

	char dayOfWeek = (FirstDayZeroYear + itsDays - 1) % AmountDaysPerWeek;
	dayOfWeek = (dayOfWeek + shift) % AmountDaysPerWeek;
	return dayOfWeek ? dayOfWeek : Date::Sunday;
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
	year = year < 0 ? -year : year;
	return !(year % 400) || (!(year % 4) && (year % 100));
}

bool Date::IsBetween(const Date& theDate, const Date& startDate, const Date& endDate)
{
	return (theDate >= startDate)
		&& (theDate <= endDate);
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

Date operator+(const Date& left, const int& right)
{
	short year = left.itsYear;
	int days = left.itsDays + right;
	while (days / Date::AmountOfDayYear(year))
	{
		days -= Date::AmountOfDayYear(year);
		year++;
	}
	Date date(1, 1, 1);
	date.itsYear = year;
	date.itsDays = days;
	return date;
}

Date operator-(const Date& left, const int& right)
{
	short year = left.itsYear;
	int days = left.itsDays - right;
	while (days < 0) 
	{
		days += Date::AmountOfDayYear(year - 1);
		year--;
	}
	Date date(1, 1, 1);
	date.itsYear = year;
	date.itsDays = days;
	return date;
}

Date& Date::operator+=(const int& right)
{
	(*this) = (*this) + right;
	return (*this);
}

Date& Date::operator-=(const int& right)
{
	(*this) = (*this) - right;
	return (*this);
}

Date& Date::operator++() //preincrement
{
	(*this) += 1;
	return (*this);
}

Date Date::operator++(int) //postincrement
{
	Date oldValue = (*this);
	++(*this);
	return oldValue;
}

Date& Date::operator--() //predecrement
{
	(*this) -= 1;
	return (*this);
}

Date Date::operator--(int) //postdecrement
{
	Date oldValue = (*this);
	--(*this);
	return oldValue;
}