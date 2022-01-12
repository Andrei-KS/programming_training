#ifndef __CHRONO_H__
#define __CHRONO_H__

#include <istream>
#include <ostream>

namespace Chrono
{
	enum class Day
	{
		sunday,
		monday,
		tuesday,
		wednesday,
		thursday,
		friday,
		saturday
	};

	/*
	* An enum Month specify its set of values
	* as symbolic constants. Where January corresponds to 1
	*/
	enum class Month
	{
		jan = 1,
		feb,
		mar,
		apr,
		may,
		jun,
		jul,
		aug,
		sep,
		oct,
		nov,
		dec,
	};

	/*
	* 
	*/
	class Date
	{
	public:
		/* to throw as exception */
		class Invalid {};

		/* check for valid date and initialize */
		Date(int year, Month month, int day);

		/* default constructor */
		Date();

		// the default copy operations are fine


		// nonmodifying operations:
		/*
		* @return day of Date
		*/
		int day() const { return itsDay; }

		/*
		* @return month of Date
		*/
		Month month() const { return itsMonth; }

		/*
		* @return year of Date
		*/
		int year() const { return itsYear; }


		// modifying operations:
		/*
		* 
		*/
		void add_day(int n);

		/*
		* 
		*/
		void add_month(int n);

		/*
		* 
		*/
		void add_year(int n);

	private:
		/* Year of Date */
		int itsYear;

		/* Month of Date */
		Month itsMonth;

		/* Day of Date */
		int itsDay;
	};

	/*
	* @param year
	* @param month
	* @param day
	* @return true for valid date
	*/
	bool is_date(int year, Month month, int day);

	/*
	* @param year
	* @return true if year is a leap year
	*/
	bool leapyear(int year);

	bool operator==(const Date& left, const Date& right);
	bool operator!=(const Date& left, const Date& right);

	std::ostream& operator<<(std::ostream& os, const Date& date);
	std::istream& operator>>(std::istream& is, Date& date);

	/*
	* @return Day of week of day
	*/
	Day day_of_week(const Date& day);

	/*
	* @return next Sunday after date
	*/
	Date next_Sunday(const Date date);

	/*
	* @return next weekday after date
	*/
	Date next_weekday(const Date& date);

} // namespace Chrono

#endif // !__CHRONO_H__