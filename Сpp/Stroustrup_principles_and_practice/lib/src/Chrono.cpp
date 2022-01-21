#include "Chrono.h"

namespace Chrono
{
	// member function definitions:
	Date::Date(int year, Month month, int day)
		: itsYear{ year },
		itsMonth{ month },
		itsDay{ day }
	{
		if (!is_date(itsYear, itsMonth, itsDay))
		{
			throw Invalid{};
		}
	}

	const Date& default_date()
	{
		// start of 21st century
		static Date date{ 2001,Month::jan,1 }; 
		return date;
	}

	Date::Date()
		:itsYear{ default_date().year() },
		itsMonth{ default_date().month() },
		itsDay{ default_date().day() }
	{
	}

	void Date::add_day(int n)
	{
		// TODO
	}

	void Date::add_month(int n)
	{
		// TODO
	}

	void Date::add_year(int n)
	{
		if (itsMonth == Month::feb && itsDay == 29 && !leapyear(itsYear + n))
		{ // beware of leap years!
			itsMonth = Month::mar; // use March 1 instead of February 29
			itsDay = 1;
		}
		itsYear += n;
	}


	// helper functions:
	bool is_date(int year, Month month, int day)
	{
		// assume that year is valid
		
		// day must be positive
		if (day <= 0)
		{
			return false;
		}

		if (month < Month::jan || Month::dec < month)
		{
			return false;
		}

		// most months have 31 days
		int days_in_month = 31; 

		switch (month) {
		case Month::feb:
			// the length of February varies
			days_in_month = (leapyear(year)) ? 29 : 28;
			break;

		case Month::apr:
		case Month::jun:
		case Month::sep:
		case Month::nov:
			// the rest have 30 days
			days_in_month = 30; 
			break;
		}

		if (days_in_month < day)
		{
			return false;
		}

		return true;
	}

	bool leapyear(int year)
	{
		year = year < 0 ? -year : year;
		return !(year % 400) || (!(year % 4) && (year % 100));
	}

	bool operator==(const Date& left, const Date& right)
	{
		return left.year() == right.year()
			&& left.month() == right.month()
			&& left.day() == right.day();
	}

	bool operator!=(const Date& left, const Date& right)
	{
		return !(left == right);
	}

	std::ostream& operator<<(std::ostream& os, const Date& date)
	{
		return os << '(' << date.year()
			<< ',' << static_cast<int>(date.month())
			<< ',' << date.day() << ')';
	}

	std::istream& operator>>(std::istream& is, Date& date)
	{
		int year, month, day;
		char ch1, ch2, ch3, ch4;
		is >> ch1 >> year >> ch2 >> month >> ch3 >> day >> ch4;

		if (!is)
		{
			return is;
		}

		if (ch1 != '(' || ch2 != ',' || ch3 != ',' || ch4 != ')')
		{ // oops: format error
			// set the fail bit
			is.clear(std::ios_base::failbit); 
			return is;
		}

		// update date
		date = Date(year, Month(month), day);

		return is;
	}

	Day day_of_week(const Date& date)
	{
		// TODO
		throw Chrono::Date::Invalid();
		return Day::monday;
	}

	Date next_Sunday(const Date& date)
	{
		// TODO
		throw Chrono::Date::Invalid();
		return Date();
	}

	Date next_weekday(const Date& date)
	{
		// TODO
		throw Chrono::Date::Invalid();
		return Date();
	}

} // namespace Chrono