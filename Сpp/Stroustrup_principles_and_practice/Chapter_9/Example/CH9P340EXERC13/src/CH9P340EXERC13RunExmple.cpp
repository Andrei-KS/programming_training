/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 01/30/2022 00:03:23
	author                                       : Andrei-KS
*/

#include "CH9P340EXERC13RunExmple.h"
#include "std_lib_facilities.h"
#include "Rational.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH9P340EXERC13RunExmple();

namespace {
	void test_swap(const int left, const int right)
	{
		int currleft = left;
		int currRight = right;
		MyLib::swap(currleft, currRight);
		if (currleft != right && currRight != left)
		{
			error("test_swap(" + std::to_string(left) + ", " + std::to_string(right) + ") :: Fail");
		}
	}

	void test_greatest_common_divisor(int left, int right, int correctValue)
	{
		if (MyLib::greatest_common_divisor(left,right) != correctValue)
		{
			error("test_greatest_common_divisor(" + std::to_string(left) + ", " + std::to_string(right) + ", "+ std::to_string(correctValue) +") :: Fail");
		}
	}

	void test_rational(int numerator, int denominator, int correctValueNumerator, int correctValueDenominator)
	{
		MyLib::Rational rational(numerator, denominator);
		if(rational.numerator() != correctValueNumerator || rational.denominator() != correctValueDenominator)
		{
			error("test_rational(" + std::to_string(numerator) + ", " + std::to_string(denominator) + ", " + std::to_string(correctValueNumerator) + ", " + std::to_string(correctValueDenominator) +") :: Fail");
		}
	}

	void test_sum_rationals(MyLib::Rational left, MyLib::Rational right, MyLib::Rational correctValue)
	{
		MyLib::Rational result = left + right;
		if (result != correctValue)
		{
			error("test_sum_rationals(...) :: Fail");
		}
	}

	void test_subtraction_rationals(MyLib::Rational left, MyLib::Rational right, MyLib::Rational correctValue)
	{
		MyLib::Rational result = left - right;
		if (result != correctValue)
		{
			error("test_subtraction_rationals(...) :: Fail");
		}
	}

	void test_multiplication_rationals(MyLib::Rational left, MyLib::Rational right, MyLib::Rational correctValue)
	{
		MyLib::Rational result = left * right;
		if (result != correctValue)
		{
			error("test_multiplication_rationals(...) :: Fail");
		}
	}

	void test_division_rationals(MyLib::Rational left, MyLib::Rational right, MyLib::Rational correctValue)
	{
		MyLib::Rational result = left / right;
		if (result != correctValue)
		{
			error("test_multiplication_rationals(...) :: Fail");
		}
	}
}

int CH9P340EXERC13RunExmple::excute()
{
	try
	{
		test_swap(1, 2);
	}
	catch (const std::exception& e)
	{
		cout << "Test 1: " << e.what() << "\n";
	}

	try
	{
		test_greatest_common_divisor(1, 5, 1);
		test_greatest_common_divisor(5, 1, 1);
		test_greatest_common_divisor(5, 5, 5);
		test_greatest_common_divisor(6, 4, 2);
		test_greatest_common_divisor(21, 14, 7);
	}
	catch (const std::exception& e)
	{
		cout << "Test 2: " << e.what() << "\n";
	}

	try
	{
		test_rational(1, 1, 1, 1);
		test_rational(2, 1, 2, 1);
		test_rational(1, 2, 1, 2);
		test_rational(21, 14, 3, 2);
		test_rational(0, 5, 0, 1);
	}
	catch (const std::exception& e)
	{
		cout << "Test 3: " << e.what() << "\n";
	}

	try
	{
		test_sum_rationals(MyLib::Rational(3,10), MyLib::Rational(2, 5), MyLib::Rational(7, 10));
		test_sum_rationals(MyLib::Rational(1,3), MyLib::Rational(1, 2), MyLib::Rational(5, 6));
		test_sum_rationals(MyLib::Rational(1,4), MyLib::Rational(1, 6), MyLib::Rational(5, 12));
	}
	catch (const std::exception& e)
	{
		cout << "Test 4: " << e.what() << "\n";
	}

	try
	{
		test_subtraction_rationals(MyLib::Rational(7, 10), MyLib::Rational(2, 5), MyLib::Rational(3, 10));
		test_subtraction_rationals(MyLib::Rational(5, 6), MyLib::Rational(1, 2), MyLib::Rational(1, 3));
		test_subtraction_rationals(MyLib::Rational(5, 12), MyLib::Rational(1, 6), MyLib::Rational(1, 4));
	}
	catch (const std::exception& e)
	{
		cout << "Test 5: " << e.what() << "\n";
	}
	
	try
	{
		test_multiplication_rationals(MyLib::Rational(1, 2), MyLib::Rational(1, 2), MyLib::Rational(1, 4));
		test_multiplication_rationals(MyLib::Rational(1, 3), MyLib::Rational(1, 2), MyLib::Rational(1, 6));
		test_multiplication_rationals(MyLib::Rational(2, 3), MyLib::Rational(3, 4), MyLib::Rational(1, 2));
		test_multiplication_rationals(MyLib::Rational(10, 1), MyLib::Rational(3, 5), MyLib::Rational(6, 1));
		test_multiplication_rationals(MyLib::Rational(0, 1), MyLib::Rational(3, 5), MyLib::Rational(0, 1));
		test_multiplication_rationals(MyLib::Rational(-10, 1), MyLib::Rational(3, 5), MyLib::Rational(-6, 1));
	}
	catch (const std::exception& e)
	{
		cout << "Test 6: " << e.what() << "\n";
	}

	try
	{
		test_division_rationals(MyLib::Rational(1, 4), MyLib::Rational(1, 2), MyLib::Rational(1, 2));
		test_division_rationals(MyLib::Rational(1, 6), MyLib::Rational(1, 2), MyLib::Rational(1, 3));
		test_division_rationals(MyLib::Rational(1, 2), MyLib::Rational(3, 4), MyLib::Rational(2, 3));
		test_division_rationals(MyLib::Rational(6, 1), MyLib::Rational(3, 5), MyLib::Rational(10, 1));
		test_division_rationals(MyLib::Rational(-6, 1), MyLib::Rational(3, 5), MyLib::Rational(-10, 1));
	}
	catch (const std::exception& e)
	{
		cout << "Test 7: " << e.what() << "\n";
	}

	int denominator = 7;
	for (int numerator = 0; numerator < denominator * 2; numerator++)
	{
		cout << "Rational : " << numerator << " / " << denominator << " :: double :: " << static_cast<double>(MyLib::Rational(numerator, denominator)) << "\n";
	}
	

	return 0;
}