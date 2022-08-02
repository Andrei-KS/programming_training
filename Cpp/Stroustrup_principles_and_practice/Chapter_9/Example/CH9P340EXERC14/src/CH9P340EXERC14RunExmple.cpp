/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 02/01/2022 09:15:09
	author														: Andrei-KS
*/

#include "CH9P340EXERC14RunExmple.h"
#include "std_lib_facilities.h"
#include "Money.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH9P340EXERC14RunExmple();

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

	void test_rounding_to_hundredths(double value, double correctValue)
	{
		if (MyLib::rounding_to_hundredths(value) != correctValue)
		{
			error("test_rounding_to_hundredths():: Fail");
		}
	}

	void test_multiplication_money_and_value(const MyLib::Money& left, const double right, const MyLib::Money correctValue)
	{
		MyLib::Money result = left * right;
		if (result != correctValue)
		{
			error("test_test_multiplication_money_and_value():: Fail");
		}
	}

	void test_multiplication_value_and_money(const double left, const MyLib::Money& right, const MyLib::Money correctValue)
	{
		MyLib::Money result = left * right;
		if (result != correctValue)
		{
			error("test_multiplication_value_and_money():: Fail");
		}
	}

	void test_division_money_and_value(const MyLib::Money& left, const double right, const MyLib::Money correctValue)
	{
		MyLib::Money result = left / right;
		if (result != correctValue)
		{
			error("test_division_money_and_value():: Fail");
		}
	}
}

int CH9P340EXERC14RunExmple::excute()
{
	try
	{
		test_sum_money_and_money(MyLib::Money(1), MyLib::Money(2), MyLib::Money(3));
		//MyLib::Money result = MyLib::Money() + 5; // OK, it don't have to sumed
		//MyLib::Money result = 5 + MyLib::Money(); // OK, it don't have to sumed
	}
	catch (const std::exception& e)
	{
		cout << "Test 1: " << e.what() << "\n";
	}

	try
	{
		test_subtraction_money_and_money(MyLib::Money(1), MyLib::Money(2), MyLib::Money(-1));
		//MyLib::Money result = MyLib::Money() - 5; // OK, it don't have to sumed
		//MyLib::Money result = 5 - MyLib::Money(); // OK, it don't have to sumed
	}
	catch (const std::exception& e)
	{
		cout << "Test 2: " << e.what() << "\n";
	}

	try
	{
		vector<double> value =			{ 0.01, 0.02, 0.011, 0.015, 0.014, 0.033};
		vector<double> correctValue =	{ 0.01, 0.02, 0.010, 0.020, 0.010, 0.030};
		for (size_t i = 0; i < value.size(); i++)
		{
			test_rounding_to_hundredths(value[i], correctValue[i]);
		}
	}
	catch (const std::exception& e)
	{
		cout << "Test 3: " << e.what() << "\n";
	}

	try
	{
		test_multiplication_money_and_value(MyLib::Money(1), 5, MyLib::Money(5));
		test_multiplication_money_and_value(MyLib::Money(1), 0.5, MyLib::Money(1));
		test_multiplication_money_and_value(MyLib::Money(1), 0.4, MyLib::Money(0));
		test_multiplication_money_and_value(MyLib::Money(10), 0.4, MyLib::Money(4));
		test_multiplication_money_and_value(MyLib::Money(100), 0.3, MyLib::Money(30));
		//MyLib::Money result = MyLib::Money() * MyLib::Money(); // OK, it don't have to multiple
	}
	catch (const std::exception& e)
	{
		cout << "Test 4: " << e.what() << "\n";
	}

	try
	{
		test_multiplication_value_and_money(5, MyLib::Money(1), MyLib::Money(5));
		test_multiplication_value_and_money(0.5, MyLib::Money(1), MyLib::Money(1));
		test_multiplication_value_and_money(0.4, MyLib::Money(1), MyLib::Money(0));
		test_multiplication_value_and_money(0.4, MyLib::Money(10), MyLib::Money(4));
		test_multiplication_value_and_money(0.3, MyLib::Money(100), MyLib::Money(30));
		//MyLib::Money result = MyLib::Money() * MyLib::Money(); // OK, it don't have to multiple
	}
	catch (const std::exception& e)
	{
		cout << "Test 5: " << e.what() << "\n";
	}

	try
	{
		test_division_money_and_value(MyLib::Money(1), 1, MyLib::Money(1));
		test_division_money_and_value(MyLib::Money(1), 2, MyLib::Money(1));
		test_division_money_and_value(MyLib::Money(1), 3, MyLib::Money(0));
		test_division_money_and_value(MyLib::Money(10), 3, MyLib::Money(3));
		test_division_money_and_value(MyLib::Money(100), 3, MyLib::Money(33));
		//MyLib::Money result = MyLib::Money() / MyLib::Money(); // OK, it don't have to divise
	}
	catch (const std::exception& e)
	{
		cout << "Test 6: " << e.what() << "\n";
	}

	return 0;
}