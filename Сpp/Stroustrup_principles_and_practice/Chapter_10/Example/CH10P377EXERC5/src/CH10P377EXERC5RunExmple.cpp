/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/11/2022 12:12:13
	author														: Andrei-KS
*/

#include "CH10P377EXERC5RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P377EXERC5RunExmple();

/*
A file of temperature readings that has been structured like this:
- A fi le holds years (of months of readings).
- A year starts with { year followed by an integer giving the year, such as 1900, and ends with }.
- A year holds months (of days of readings).
- A month starts with { month followed by a three-letter month name, such as jan, and ends with }.
- A reading holds a time and a temperature.
- A reading starts with a ( followed by day of the month, hour of the day, and temperature and ends with a ).
For example:
{ year 1990 }
{year 1991 { month jun }}
{ year 1992 { month jan ( 1 0 61.5) } {month feb (1 1 64) (2 2 65.2) } }
{year 2000
 { month feb (1 1 68 ) (2 3 66.66 ) ( 1 0 67.2)}
 {month dec (15 15 –9.2 ) (15 14 –8.8) (14 0 –2) }
 }
*/

namespace {
	const int not_a_reading = -7777;	// less than absolute zero
	const int not_a_month = -1;		// month  number can't be negative

	struct Day {
		vector<double> hour{ vector<double>(24,not_a_reading) };
	};

	/*
	* A month of temperature readings
	*/
	struct Month {
		/* [0:11] January is 0 */
		int month{ not_a_month };
		
		/* [1:31] one vector of reading per day */
		vector<Day>day{ 32 };
	};

	/*
	* A year of temperature reading, organized by month
	*/
	struct Year {
		/* positive == A.D. */
		int year;

		/* [0:11] January is 0 */
		vector<Month> month{ 12 };
	};

	/*
	* The Reading class will be used only for reading input
	*/
	struct Reading {
		int day;
		int hour;
		double temperature;
	};

	void end_of_loop(istream& ist, char term, const string& message)
	{
		if (ist.fail()) // use term as terminator and/or separator
		{
			ist.clear();
			char ch;
			if (ist >> ch && ch == term)
			{
				return;
			}
			error(message);
		}
	}

	/*
	* read a temperature reading from is into r
	* format: ( 3 4 9.7 )
	* check format, but don't bother with data validity
	*/
	istream& operator>>(istream& is, Reading& reading)
	{
		char ch1;
		if (is >> ch1 && ch1 != '(') // could it be a Reading?
		{
			is.unget();
			is.clear(ios_base::failbit);
			return is;
		}

		char ch2;
		int day;
		int hour;
		double temperatrue;
		is >> day >> hour >> temperatrue >> ch2;
		if (!is || ch2 != ')') // messed-up reading
		{
			error("bad reading");
		}

		reading.day = day;
		reading.hour = hour;
		reading.temperature = temperatrue;
		return is;
	}

	int month_to_int(const string& month);
	bool is_valid(const Reading& reading);
	/*
	* read a month from is into month
	* format: { month feb ... }
	*/
	istream& operator>>(istream& is, Month& month)
	{
		char ch = 0;
		if (is >> ch && ch != '{')
		{
			is.unget();
			is.clear(ios_base::failbit); // we failed to read a Month
			return is;
		}

		string month_marker;
		string mm;
		is >> month_marker >> mm;
		if (!is || month_marker != "month")
		{
			error("bad start of month");
		}

		month.month = month_to_int(mm);
		int duplicates = 0;
		int invalids = 0;
		for (Reading reading; is >> reading;)
		{
			if (is_valid(reading))
			{
				if (month.day[reading.day].hour[reading.hour] != not_a_reading)
				{
					++duplicates;
				}
				month.day[reading.day].hour[reading.hour] = reading.temperature;
			}
			else
			{
				++invalids;
			}
		}

		if (invalids)
		{
			error("invalid readings in month", invalids);
		}
		if (duplicates)
		{
			error("duplicate reading in moth", duplicates);
		}
		end_of_loop(is, '}', "bad end of month");
		return is;
	}

	/*
	* read a year from is into y
	* format: { year 1972 . . . }
	*/
	istream& operator>>(istream& is, Year& year)
	{
		char ch;
		is >> ch;
		if (ch != '{')
		{
			is.unget();
			is.clear(ios_base::failbit);
			return is;
		}

		string year_marker;
		int yy;
		is >> year_marker >> yy;
		if (!is || year_marker != "year")
		{
			error("bad start of year");
		}

		year.year = yy;

		for (Month month; is >> month; )
		{
			year.month[month.month] = month;
			month = Month{}; // “reinitialize” m
		}
		end_of_loop(is, '}', "bad end of year");
		return is;
	}

	string int_to_month(int month);

	void print_year(ostream& ost, const Year& year)
	{
		ost << "{ year " << year.year;
		for (int month_index = 0; month_index < 12; ++month_index)
		{
			if (year.month[month_index].month != not_a_month)
			{
				const Month& current_month = year.month[month_index];
				ost << " { month " << int_to_month(current_month.month);
				for (int day_index = 0; day_index < 32; ++day_index)
				{
					const Day& current_day = current_month.day[day_index];
					for (int hour_index = 0; hour_index < 24; ++hour_index)
					{
						if (current_day.hour[hour_index] != not_a_reading)
						{
							ost << "( " << day_index
								<< ", " << hour_index
								<< ", " << current_day.hour[hour_index]
								<< ")";
						}
					}
				}
			}
		}

		ost << " }\n";
	}

	/*------------------------------------------------------------------
											Helper function
	------------------------------------------------------------------*/
	constexpr int implausible_min = -200;
	constexpr int implausible_max = 200;

	/*
	* A rough test
	*/
	bool is_valid(const Reading& reading)
	{
		if (reading.day < 1 || 31 < reading.day)
		{
			return false;
		}
		if (reading.hour < 0 || 23 < reading.hour)
		{
			return false;
		}
		if (reading.temperature < implausible_min || implausible_max < reading.temperature)
		{
			return false;
		}
		return true;
	}

	vector<string> month_input_tbl = {
			"jan", "feb", "mar", "apr", "may", "jun", "jul",
			"aug", "sep", "oct", "nov", "dec"
	};

	/*
	* is s the name of a month? If so return its index [0:11] otherwise –1
	*/
	int month_to_int(const string& month)
	{
		for (int i = 0; i < 12; ++i) if (month_input_tbl[i] == month) return i;
		return -1;
	}

	vector<string> month_print_tbl = {
			"January", "February", "March", "April", "May", "June", "July",
			"August", "September", "October", "November", "December"
	};

	/*
	* months [0:11]
	*/
	string int_to_month(int i)
	{
		if (i < 0 || 12 <= i) error("bad month index");
		return month_print_tbl[i];
	}
}

int CH10P377EXERC5RunExmple::excute()
{
	// open an input file:
	cout << "Please enter input file name\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)
	{
		error("can't open input file", iname);
	}
	ifs.exceptions(ifs.exceptions() | ios_base::badbit); // throw for bad()

	// open an output file:
	cout << "Please enter output file name\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs)
	{
		error("can't open output file", oname);
	}

	// read an arbitrary number of years:
	vector<Year> years;
	while (true)
	{
		Year year; // get a freshly initialized Year each time around
		if (!(ifs >> year))
		{
			break;
		}
		years.push_back(year);
	}

	cout << "read " << years.size() << " years of readings\n";
	for (Year& year : years)
	{
		print_year(ofs, year);
	}

	return 0;
}