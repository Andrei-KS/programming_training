/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 01/24/2022 09:52:40
	author														: Andrei-KS
*/

#include "CH9P340EXERC11RunExmple.h"
#include "std_lib_facilities.h"
#include "Chrono.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH9P340EXERC11RunExmple();

namespace {
	void test_add_day(Chrono::Date date, int amountDays, const Chrono::Date& correctDayValue)
	{
		date.add_day(amountDays);
		if (date != correctDayValue)
		{
			error("test_add_day(" + std::to_string(amountDays) +") :: Fail");
		}
	}

	void test_next_sunday(Chrono::Date date, const Chrono::Date& correctDayValue)
	{
		date = Chrono::next_sunday(date);
		if (date != correctDayValue)
		{
			error("test_next_sunday() :: Fail");
		}
	}

	void test_next_weekday(Chrono::Date date, const Chrono::Date& correctDayValue)
	{
		date = Chrono::next_weekday(date);
		if (date != correctDayValue)
		{
			error("test_next_sunday() :: Fail");
		}
	}

	void test_add_month(Chrono::Date date, int amountMonths, const Chrono::Date& correctDayValue)
	{
		date.add_month(amountMonths);
		if (date != correctDayValue)
		{
			error("test_add_month(" + std::to_string(amountMonths) + ") :: Fail");
		}
	}
}

int CH9P340EXERC11RunExmple::excute()
{
	Chrono::Date date(0, Chrono::Month::jan, 1);
	Chrono::Day d = Chrono::day_of_week(date);
	Chrono::Date date2(2022, Chrono::Month::jan, 25);
	Chrono::Day d2 = Chrono::day_of_week(date2);
	Chrono::Date date3(2021, Chrono::Month::jan, 25);
	Chrono::Day d3 = Chrono::day_of_week(date3);
	try
	{
		test_add_day(Chrono::Date(0, Chrono::Month::jan, 1), 1, Chrono::Date(0, Chrono::Month::jan, 2));
		test_add_day(Chrono::Date(0, Chrono::Month::jan, 1), 30, Chrono::Date(0, Chrono::Month::jan, 31));
		test_add_day(Chrono::Date(0, Chrono::Month::jan, 1), 31, Chrono::Date(0, Chrono::Month::feb, 1));
		test_add_day(Chrono::Date(0, Chrono::Month::jan, 1), 59, Chrono::Date(0, Chrono::Month::feb, 29));
		test_add_day(Chrono::Date(0, Chrono::Month::jan, 1), 60, Chrono::Date(0, Chrono::Month::mar, 1));
		test_add_day(Chrono::Date(0, Chrono::Month::jan, 1), 365, Chrono::Date(0, Chrono::Month::dec, 31));
		test_add_day(Chrono::Date(0, Chrono::Month::jan, 1), 1461, Chrono::Date(4, Chrono::Month::jan, 1));
		test_add_day(Chrono::Date(0, Chrono::Month::jan, 1), 36524, Chrono::Date(99, Chrono::Month::dec, 31));
		test_add_day(Chrono::Date(0, Chrono::Month::jan, 1), 146097, Chrono::Date(400, Chrono::Month::jan, 1)); 
		test_add_day(Chrono::Date(0, Chrono::Month::jan, 1), 219145, Chrono::Date(599, Chrono::Month::dec, 31));
	}
	catch (const std::exception& e)
	{
		cout << "Test 1: " << e.what() << "\n";
	}

	try
	{
		test_add_day(Chrono::Date(1, Chrono::Month::jan, 1), 1, Chrono::Date(1, Chrono::Month::jan, 2));
		test_add_day(Chrono::Date(1, Chrono::Month::jan, 1), 30, Chrono::Date(1, Chrono::Month::jan, 31));
		test_add_day(Chrono::Date(1, Chrono::Month::jan, 1), 31, Chrono::Date(1, Chrono::Month::feb, 1));
		test_add_day(Chrono::Date(1, Chrono::Month::jan, 1), 59, Chrono::Date(1, Chrono::Month::mar, 1));
		test_add_day(Chrono::Date(1, Chrono::Month::jan, 1), 60, Chrono::Date(1, Chrono::Month::mar, 2));
		test_add_day(Chrono::Date(1, Chrono::Month::jan, 1), 365, Chrono::Date(2, Chrono::Month::jan, 1));
		test_add_day(Chrono::Date(1, Chrono::Month::jan, 1), 1461, Chrono::Date(5, Chrono::Month::jan, 1));
		test_add_day(Chrono::Date(1, Chrono::Month::jan, 1), 36524, Chrono::Date(101, Chrono::Month::jan, 1));
		test_add_day(Chrono::Date(1, Chrono::Month::jan, 1), 146097, Chrono::Date(401, Chrono::Month::jan, 1));
		test_add_day(Chrono::Date(1, Chrono::Month::jan, 1), 219145, Chrono::Date(601, Chrono::Month::jan, 1));
	}
	catch (const std::exception& e)
	{
		cout << "Test 2: " << e.what() << "\n";
	}

	try
	{
		test_add_day(Chrono::Date(4000, Chrono::Month::jan, 1), -1, Chrono::Date(3999, Chrono::Month::dec, 31));
		test_add_day(Chrono::Date(4000, Chrono::Month::jan, 1), -30, Chrono::Date(3999, Chrono::Month::dec, 2));
		test_add_day(Chrono::Date(4000, Chrono::Month::jan, 1), -31, Chrono::Date(3999, Chrono::Month::dec, 1));
		test_add_day(Chrono::Date(4000, Chrono::Month::jan, 1), -59, Chrono::Date(3999, Chrono::Month::nov, 3));
		test_add_day(Chrono::Date(4000, Chrono::Month::jan, 1), -60, Chrono::Date(3999, Chrono::Month::nov, 2));
		test_add_day(Chrono::Date(4000, Chrono::Month::jan, 1), -365, Chrono::Date(3999, Chrono::Month::jan, 1));
		test_add_day(Chrono::Date(4000, Chrono::Month::jan, 1), -1461, Chrono::Date(3996, Chrono::Month::jan, 1));
		test_add_day(Chrono::Date(4000, Chrono::Month::jan, 1), -36524, Chrono::Date(3900, Chrono::Month::jan, 1));
		test_add_day(Chrono::Date(4000, Chrono::Month::jan, 1), -146097, Chrono::Date(3600, Chrono::Month::jan, 1));
		test_add_day(Chrono::Date(4000, Chrono::Month::jan, 1), -219145, Chrono::Date(3400, Chrono::Month::jan, 1));
	}
	catch (const std::exception& e)
	{
		cout << "Test 3: " << e.what() << "\n";
	}

	try
	{
		test_add_day(Chrono::Date(4001, Chrono::Month::jan, 1), -1, Chrono::Date(4000, Chrono::Month::dec, 31));
		test_add_day(Chrono::Date(4001, Chrono::Month::jan, 1), -30, Chrono::Date(4000, Chrono::Month::dec, 2));
		test_add_day(Chrono::Date(4001, Chrono::Month::jan, 1), -31, Chrono::Date(4000, Chrono::Month::dec, 1));
		test_add_day(Chrono::Date(4001, Chrono::Month::jan, 1), -59, Chrono::Date(4000, Chrono::Month::nov, 3));
		test_add_day(Chrono::Date(4001, Chrono::Month::jan, 1), -60, Chrono::Date(4000, Chrono::Month::nov, 2));
		test_add_day(Chrono::Date(4001, Chrono::Month::jan, 1), -365, Chrono::Date(4000, Chrono::Month::jan, 2));
		test_add_day(Chrono::Date(4001, Chrono::Month::jan, 1), -1461, Chrono::Date(3997, Chrono::Month::jan, 1));
		test_add_day(Chrono::Date(4001, Chrono::Month::jan, 1), -36524, Chrono::Date(3901, Chrono::Month::jan, 2));
		test_add_day(Chrono::Date(4001, Chrono::Month::jan, 1), -146097, Chrono::Date(3601, Chrono::Month::jan, 1));
		test_add_day(Chrono::Date(4001, Chrono::Month::jan, 1), -219145, Chrono::Date(3401, Chrono::Month::jan, 2));
	}
	catch (const std::exception& e)
	{
		cout << "Test 4: " << e.what() << "\n";
	}

	try
	{
		test_next_sunday(Chrono::Date(2022, Chrono::Month::jan, 23), Chrono::Date(2022, Chrono::Month::jan, 30));
		test_next_sunday(Chrono::Date(2022, Chrono::Month::jan, 24), Chrono::Date(2022, Chrono::Month::jan, 30));
		test_next_sunday(Chrono::Date(2022, Chrono::Month::jan, 25), Chrono::Date(2022, Chrono::Month::jan, 30));
		test_next_sunday(Chrono::Date(2022, Chrono::Month::jan, 26), Chrono::Date(2022, Chrono::Month::jan, 30));
		test_next_sunday(Chrono::Date(2022, Chrono::Month::jan, 27), Chrono::Date(2022, Chrono::Month::jan, 30));
		test_next_sunday(Chrono::Date(2022, Chrono::Month::jan, 28), Chrono::Date(2022, Chrono::Month::jan, 30));
		test_next_sunday(Chrono::Date(2022, Chrono::Month::jan, 29), Chrono::Date(2022, Chrono::Month::jan, 30));
	}
	catch (const std::exception& e)
	{
		cout << "Test 5: " << e.what() << "\n";
	}

	try
	{
		test_next_weekday(Chrono::Date(2022, Chrono::Month::jan, 23), Chrono::Date(2022, Chrono::Month::jan, 24));
		test_next_weekday(Chrono::Date(2022, Chrono::Month::jan, 24), Chrono::Date(2022, Chrono::Month::jan, 25));
		test_next_weekday(Chrono::Date(2022, Chrono::Month::jan, 25), Chrono::Date(2022, Chrono::Month::jan, 26));
		test_next_weekday(Chrono::Date(2022, Chrono::Month::jan, 26), Chrono::Date(2022, Chrono::Month::jan, 27));
		test_next_weekday(Chrono::Date(2022, Chrono::Month::jan, 27), Chrono::Date(2022, Chrono::Month::jan, 28));
		test_next_weekday(Chrono::Date(2022, Chrono::Month::jan, 28), Chrono::Date(2022, Chrono::Month::jan, 31));
		test_next_weekday(Chrono::Date(2022, Chrono::Month::jan, 29), Chrono::Date(2022, Chrono::Month::jan, 31));
	}
	catch (const std::exception& e)
	{
		cout << "Test 6: " << e.what() << "\n";
	}

	try
	{
		test_add_month(Chrono::Date(2000, Chrono::Month::jan, 1), 1, Chrono::Date(2000, Chrono::Month::feb, 1));
		test_add_month(Chrono::Date(2000, Chrono::Month::jan, 1), 2, Chrono::Date(2000, Chrono::Month::mar, 1));
		test_add_month(Chrono::Date(2000, Chrono::Month::jan, 1), 3, Chrono::Date(2000, Chrono::Month::apr, 1));
		test_add_month(Chrono::Date(2000, Chrono::Month::jan, 1), 11, Chrono::Date(2000, Chrono::Month::dec, 1));
		test_add_month(Chrono::Date(2000, Chrono::Month::jan, 1), 12, Chrono::Date(2001, Chrono::Month::jan, 1));
		test_add_month(Chrono::Date(2000, Chrono::Month::jan, 31), 1, Chrono::Date(2000, Chrono::Month::feb, 29));
		test_add_month(Chrono::Date(2000, Chrono::Month::jan, 31), 13, Chrono::Date(2001, Chrono::Month::feb, 28));
		test_add_month(Chrono::Date(2000, Chrono::Month::jan, 31), 3, Chrono::Date(2000, Chrono::Month::apr, 30));
		test_add_month(Chrono::Date(2000, Chrono::Month::nov, 30), 2, Chrono::Date(2001, Chrono::Month::jan, 30));
	}
	catch (const std::exception& e)
	{
		cout << "Test 7: " << e.what() << "\n";
	}

	try
	{
		test_add_month(Chrono::Date(2001, Chrono::Month::jan, 1), -1, Chrono::Date(2000, Chrono::Month::dec, 1));
		test_add_month(Chrono::Date(2001, Chrono::Month::jan, 1), -2, Chrono::Date(2000, Chrono::Month::nov, 1));
		test_add_month(Chrono::Date(2001, Chrono::Month::jan, 1), -3, Chrono::Date(2000, Chrono::Month::oct, 1));
		test_add_month(Chrono::Date(2001, Chrono::Month::jan, 1), -11, Chrono::Date(2000, Chrono::Month::feb, 1));
		test_add_month(Chrono::Date(2001, Chrono::Month::jan, 1), -12, Chrono::Date(2000, Chrono::Month::jan, 1));
		test_add_month(Chrono::Date(2001, Chrono::Month::jan, 31), -11, Chrono::Date(2000, Chrono::Month::feb, 29));
		test_add_month(Chrono::Date(2001, Chrono::Month::jan, 31), -13, Chrono::Date(1999, Chrono::Month::dec, 31));
		test_add_month(Chrono::Date(2001, Chrono::Month::jan, 31), -3, Chrono::Date(2000, Chrono::Month::oct, 31));
		test_add_month(Chrono::Date(2001, Chrono::Month::nov, 30), -2, Chrono::Date(2001, Chrono::Month::sep, 30));
	}
	catch (const std::exception& e)
	{
		cout << "Test 8: " << e.what() << "\n";
	}
	return 0;
}