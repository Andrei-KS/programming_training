#include "Chrono.h"

namespace Chrono
{
	static const int MaxDayYear = 365;
	static const int MaxDayLearYear = 366;
	static const Chrono::Day FirstDayZeroYear = Chrono::Day::saturday;

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
		if (n == 0)
		{
			return;
		}

		if (n > 0)
		{
			n += elapsed_days_until_month(itsMonth, itsYear) + itsDay;
			itsMonth = Month::jan;
			itsDay = 1;

			n -= amount_of_day_year(itsYear);
			if (n <= 0)
			{
				const int maxDay = amount_of_day_year(itsYear);
				n += maxDay;
				int left = static_cast<int>(Month::jan);
				int right = static_cast<int>(Month::dec);
				int choosedMonth;
				while (left + 1 < right)
				{
					int choosedMonth = left + (right - left) / 2;
					if (elapsed_days_until_month(static_cast<Month>(choosedMonth), itsYear) < n)
					{
						left = choosedMonth;
					}
					else
					{
						right = choosedMonth;
					}
				}
				choosedMonth = left;
				if (elapsed_days_until_month(static_cast<Month>(right), itsYear) < n)
				{
					choosedMonth = right;
				}
				itsMonth = static_cast<Month>(choosedMonth);
				itsDay = n - elapsed_days_until_month(static_cast<Month>(choosedMonth), itsYear);
			}
			else
			{
				itsYear++;
				// we take one day due to transition to first day next year
				n--;

				// we sequentially remove 400 year shifts, 100 year shifts, 4 year shifts
				// from the number of days. At end we consider only remainder
				//
				// current date                          400[m]            100[m']    4[m'']    n
				//      |---------...----------------------|--------...-------|----...--|-------|
				//

				constexpr int amountDaysOf400Years = 365 * 400 + 400/4 - 400/100 + 400/400;
				const int amountDaysOf100Years = 365 * 100 + 100 / 4 - 100 / 100 + 100 / 400;
				const int amountDaysOf4Years = 365 * 4 + 4 / 4 - 4 / 100 + 4 / 400;

				itsYear += (n / amountDaysOf400Years) * 400;
				n %= amountDaysOf400Years;
				itsYear += (n / amountDaysOf100Years) * 100;
				n %= amountDaysOf100Years;
				itsYear += (n / amountDaysOf4Years) * 4;
				n %= amountDaysOf4Years;
				while (n > amount_of_day_year(itsYear))
				{
					n -= amount_of_day_year(itsYear);
					itsYear++;
				}

				add_day(n);
			}
		}
		else
		{
			// we will move back several 400 year shifts and add to them the difference
			// between the number of days of these 400 year shifts and the given number of days to be added
			//
			//  [m]            n    [m-1]                 [m-2]     current date      
			//  |--------------|------|---------------------|---- ... ----|
			//  |<--- diff --->|

			constexpr int amountDaysOf400Years = 365 * 400 + 400 / 4 - 400 / 100 + 400 / 400;
			int amountOf400YearsShifts = (-n) / amountDaysOf400Years + 1;
			n += amountOf400YearsShifts * amountDaysOf400Years;
			itsYear -= amountOf400YearsShifts * 400;

			add_day(n);
		}
	}

	void Date::add_month(int n)
	{
		if (n == 0)
		{
			return;
		}
		if (n > 0)
		{
			n += static_cast<int>(itsMonth) - 1;
			itsYear += n / 12;
			n = (n%12) + 1;
			Month desiredMonthValue = static_cast<Month>(n);
			int maxAmountDaysOfMonth = amount_days_in_month(static_cast<Month>(n), itsYear);
			itsDay = itsDay <= maxAmountDaysOfMonth ? itsDay : maxAmountDaysOfMonth;
			itsMonth = desiredMonthValue;
		}
		else
		{
			constexpr int amountMonthsOf400Years = 12 * 400;
			int amountOf400YearsShifts = (-n) / amountMonthsOf400Years + 1;
			n += amountOf400YearsShifts * amountMonthsOf400Years;
			itsYear -= amountOf400YearsShifts * 400;

			add_month(n);
		}
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

		if (amount_days_in_month(month, year) < day)
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

	int amount_of_day_year(int year)
	{
		return leapyear(year) ? MaxDayLearYear : MaxDayYear;
	}

	int amount_days_in_month(Month month, int year)
	{
		// most months have 31 days
		int daysInMonth = 31;

		switch (month) {
		case Month::feb:
			// the length of February varies
			daysInMonth = (leapyear(year)) ? 29 : 28;
			break;

		case Month::apr:
		case Month::jun:
		case Month::sep:
		case Month::nov:
			// the rest have 30 days
			daysInMonth = 30;
			break;
		}

		return daysInMonth;
	}

	int elapsed_days_until_month(Month month, int year)
	{
		static const int const elapsedDayYear[] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, /*365*/ };
		static const int const elapsedDayLeapYear[] = { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, /*366*/ };
		if (static_cast<int>(month) < 1 || static_cast<int>(month) > 12)
		{
			throw Invalid();
		}
		const int const* startDaysYear = leapyear(year) ? elapsedDayLeapYear : elapsedDayYear;
		return startDaysYear[static_cast<size_t>(month) - 1];
	}

	Day day_of_week(const Date& date)
	{
		short AmountYearsMultipleOfFour = (date.year() - 1) / 4;
		short AmountYearsMultipleOfOneHundred = (date.year() - 1) / 100;
		short AmountYearsMultipleOfFourHundred = (date.year() - 1) / 400;
		short shift = date.year() + (AmountYearsMultipleOfFour - AmountYearsMultipleOfOneHundred + AmountYearsMultipleOfFourHundred);

		// Zero year Multiple Of Four Hundred
		shift += date.year() ? 1 : 0;

		short amountDaysPerWeek = static_cast<int>(Day::saturday);
		shift %= amountDaysPerWeek;

		// we do not consider the current day as past, so we need to subtract 1 
		int dayOfWeek = (static_cast<int>(FirstDayZeroYear) + elapsed_days_until_month(date.month(), date.year()) + date.day() - 1) % amountDaysPerWeek;

		dayOfWeek = (dayOfWeek + shift) % amountDaysPerWeek;
		return dayOfWeek ? static_cast<Day>(dayOfWeek) : Day::saturday;
	}

	Date next_sunday(const Date& date)
	{
		int remmaningDayForNextSunday = 8 - static_cast<int>(day_of_week(date));
		Date answer = date;
		answer.add_day(remmaningDayForNextSunday);
		return answer;
	}

	Date next_weekday(const Date& date)
	{
		Date answer = date;
		Day currentDayofWeek = Chrono::day_of_week(date);
		switch (currentDayofWeek)
		{
		case Day::friday:
			answer.add_day(3);
			break;
		case Day::saturday:
			answer.add_day(2);
			break;
		default:
			answer.add_day(1);
			break;
		}
		return answer;
	}

} // namespace Chrono