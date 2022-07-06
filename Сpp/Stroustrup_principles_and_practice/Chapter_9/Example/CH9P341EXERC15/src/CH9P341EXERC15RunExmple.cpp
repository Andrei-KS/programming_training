/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 02/02/2022 09:05:59
	author														: Andrei-KS
*/

#include "CH9P341EXERC15RunExmple.h"
#include "std_lib_facilities.h"
#include "Money.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH9P341EXERC15RunExmple();

namespace {
	void test_sum_money_and_money(const MyLib::Money& left, const MyLib::Money& right, const MyLib::Money correctValue)
	{
		MyLib::Money result = left + right;
		if (result != correctValue)
		{
			error("test_sum_money_and_money():: Fail");
		}
	}

	void test_subtraction_money_and_money(const MyLib::Money& left, const MyLib::Money& right, const MyLib::Money correctValue)
	{
		MyLib::Money result = left - right;
		if (result != correctValue)
		{
			error("test_sum_money_and_money():: Fail");
		}
	}
}

int CH9P341EXERC15RunExmple::excute()
{
	try
	{
		test_sum_money_and_money(MyLib::Money(1,MyLib::Currency::USD), MyLib::Money(1, MyLib::Currency::USD), MyLib::Money(2, MyLib::Currency::USD));
		test_sum_money_and_money(MyLib::Money(10,MyLib::Currency::USD), MyLib::Money(10, MyLib::Currency::USD), MyLib::Money(20, MyLib::Currency::USD));
		test_sum_money_and_money(MyLib::Money(100,MyLib::Currency::USD), MyLib::Money(100, MyLib::Currency::USD), MyLib::Money(200, MyLib::Currency::USD));
		test_sum_money_and_money(MyLib::Money(1,MyLib::Currency::USD), MyLib::Money(1, MyLib::Currency::EUR), MyLib::Money(2, MyLib::Currency::USD));
		test_sum_money_and_money(MyLib::Money(10,MyLib::Currency::USD), MyLib::Money(10, MyLib::Currency::EUR), MyLib::Money(21, MyLib::Currency::USD));
		test_sum_money_and_money(MyLib::Money(100,MyLib::Currency::USD), MyLib::Money(100, MyLib::Currency::EUR), MyLib::Money(213, MyLib::Currency::USD));
		test_sum_money_and_money(MyLib::Money(1,MyLib::Currency::EUR), MyLib::Money(1, MyLib::Currency::CNY), MyLib::Money(1, MyLib::Currency::EUR));
		test_sum_money_and_money(MyLib::Money(10,MyLib::Currency::EUR), MyLib::Money(10, MyLib::Currency::CNY), MyLib::Money(11, MyLib::Currency::EUR));
		test_sum_money_and_money(MyLib::Money(100,MyLib::Currency::EUR), MyLib::Money(100, MyLib::Currency::CNY), MyLib::Money(114, MyLib::Currency::EUR));
		test_sum_money_and_money(MyLib::Money(0,MyLib::Currency::RUB), MyLib::Money(1, MyLib::Currency::EUR), MyLib::Money(86, MyLib::Currency::RUB));
	}
	catch (const std::exception& e)
	{
		cout << "Test 1: " << e.what() << "\n";
	}

	try
	{
		test_subtraction_money_and_money(MyLib::Money(1, MyLib::Currency::USD), MyLib::Money(1, MyLib::Currency::USD), MyLib::Money(0, MyLib::Currency::USD));
		test_subtraction_money_and_money(MyLib::Money(1, MyLib::Currency::USD), MyLib::Money(1, MyLib::Currency::EUR), MyLib::Money(0, MyLib::Currency::USD));
		test_subtraction_money_and_money(MyLib::Money(10, MyLib::Currency::USD), MyLib::Money(10, MyLib::Currency::EUR), MyLib::Money(-1, MyLib::Currency::USD));

	}
	catch (const std::exception& e)
	{
		cout << "Test 2: " << e.what() << "\n";
	}

	return 0;
}