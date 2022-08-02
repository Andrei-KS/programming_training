/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 07/11/2022 18:28:45
	author														: Andrei-KS
*/

#include "CH10P377EXERC6RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH10P377EXERC6RunExmple();

/*
* I 1
* V 5
* X 10
* L 50
* C 100
* D 500
* M 1000
* 
* example:
* XXXIX		39
* ccXLVI		246
* MDCCLXXVI 1776
*/

namespace {
	
	class Roman_int {
	public:
		static bool is_valid(const string& roman_str);
		Roman_int();
		int as_int();
		friend istream& operator>>(istream& ist, Roman_int& roman_int);
		friend ostream& operator<<(ostream& ost, const Roman_int& roman_int);
	private:
		int number;
	};

	Roman_int::Roman_int()
		: number(0)
	{}

	int Roman_int::as_int() { return number; }

	const int arab_array[]		= {   1,    4,   5,    9,  10,   40,  50,   90, 100,  400, 500,  900, 1000, };
	const char *roman_array[]	= { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM",  "M", };
	constexpr int size_arab_array = sizeof(arab_array) / sizeof(int);
	constexpr int size_roman_array = size_arab_array;

	string arab_to_roman(int arab_value)
	{
		string roman;
		if (!arab_value)
		{
			return string();
		}
		for (int current_max_romanar = size_roman_array - 1; current_max_romanar >= 0 && arab_value > 0; current_max_romanar--)
		{
			int current_max_arab_value = arab_array[current_max_romanar];
			int counter = arab_value / current_max_arab_value;
			if (counter == 0)
			{
				continue;
			}
			arab_value -= counter * current_max_arab_value;
			for (; counter > 0; --counter)
			{
				roman += roman_array[current_max_romanar];
			}
		}
		return roman;
	}

	int roman_to_arab(string roman_number)
	{
		int result = 0;
		int length_roman_str = roman_number.size();
		
		const char* roman_c_str = roman_number.c_str();
		int current_max_romanar = size_roman_array - 1;
		int index = 0;
		while (current_max_romanar >= 0 && index < length_roman_str)
		{
			// If we look at romanar, we can see that pair elements are in odd positions of the array
			// (index start from 0)
			int is_odded = current_max_romanar & 1;
			if (roman_c_str[index] == roman_array[current_max_romanar][0] && (!is_odded || roman_c_str[index+1] == roman_array[current_max_romanar][1]))
			{
				result += arab_array[current_max_romanar];
				index += 1 + is_odded;
			}
			else
			{
				--current_max_romanar;
			}
		}
		return result;
	}

	bool Roman_int::is_valid(const string& roman_str)
	{
		for (char current_symbol : roman_str)
		{
			bool is_valid = false;
			for (int index = 0; index < size_arab_array; index += 2)
			{
				if (current_symbol == roman_array[index][0])
				{
					is_valid = true;
					break;
				}
			}
			if (!is_valid)
			{
				return false;
			}
		}
		return true;
	}

	istream& operator>>(istream& ist, Roman_int& roman_int)
	{
		string roman_str;
		ist >> roman_str;
		if (!ist)
		{
			return ist;
		}
		if (!Roman_int::is_valid(roman_str))
		{
			error("Roman int have an invalid symbol.");
		}
		roman_int.number = roman_to_arab(roman_str);
		return ist;
	}

	ostream& operator<<(ostream& ost, const Roman_int& roman_int)
	{
		return ost << arab_to_roman(roman_int.number);
	}
}

int CH10P377EXERC6RunExmple::excute()
{
	cout << "Please enter Roman_int: ";
	Roman_int r;
	cin >> r;
	cout << "Roman_int as int: " << r.as_int() << "\n";
	cout << "int as Roman_int: " << r << "\n";
	cout << "Roman " << r << " equals " << r.as_int() << '\n';
	return 0;
}