/*
	author														: Andrei-KS
*/

#include "Roman_int.h"
#include <string>
#include <iostream>

int Roman_int::as_int() { return number; }

const int arab_array[] = { 1,    4,   5,    9,  10,   40,  50,   90, 100,  400, 500,  900, 1000, };
const char* roman_array[] = { "I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM",  "M", };
constexpr int size_arab_array = sizeof(arab_array) / sizeof(int);
constexpr int size_roman_array = size_arab_array;
constexpr int MAX_ROMAN_VALUE = 3999;
constexpr int MIN_ROMAN_VALUE = 1;

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

bool Roman_int::is_valid(const int roman_value)
{
	return !(roman_value < MIN_ROMAN_VALUE || roman_value > MAX_ROMAN_VALUE);
}

string arab_to_roman(int arab_value)
{
	string roman;
	if (!Roman_int::is_valid(arab_value))
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
		if (roman_c_str[index] == roman_array[current_max_romanar][0] && (!is_odded || roman_c_str[index + 1] == roman_array[current_max_romanar][1]))
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


Roman_int::Roman_int()
	: number(0)
{
}

Roman_int::Roman_int(const int arab_number)
	: number(arab_number)
{
}
Roman_int::Roman_int(const Roman_int& other)
	: number(other.number)
{
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

	int roman_value = roman_to_arab(roman_str);
	if (!Roman_int::is_valid(roman_value))
	{
		error("Value is unknown in Roman number", roman_value);
	}
	roman_int.number = roman_value;
	return ist;
}

ostream& operator<<(ostream& ost, const Roman_int& roman_int)
{
	return ost << arab_to_roman(roman_int.number);
}

inline bool operator==(const Roman_int& left, const Roman_int& right) { return left.number == right.number; }
inline bool operator!=(const Roman_int& left, const Roman_int& right) { return !(left == right); }
inline bool operator< (const Roman_int& lhs, const Roman_int& rhs) { return lhs.number < rhs.number; }
inline bool operator> (const Roman_int& lhs, const Roman_int& rhs) { return rhs < lhs; }
inline bool operator<=(const Roman_int& lhs, const Roman_int& rhs) { return !(lhs > rhs); }
inline bool operator>=(const Roman_int& lhs, const Roman_int& rhs) { return !(lhs < rhs); }

Roman_int operator+(Roman_int lhs, const Roman_int rhs)
{
	lhs.number += rhs.number;
	if (!Roman_int::is_valid(lhs.number))
	{
		error("Value is unknown in Roman number", lhs.number);
	}
	return lhs;
}

Roman_int operator-(Roman_int lhs, const Roman_int rhs)
{
	lhs.number -= rhs.number;
	if (!Roman_int::is_valid(lhs.number))
	{
		error("Value is unknown in Roman number", lhs.number);
	}
	return lhs;
}

Roman_int operator*(Roman_int lhs, const Roman_int rhs)
{
	lhs.number *= rhs.number;
	if (!Roman_int::is_valid(lhs.number))
	{
		error("Value is unknown in Roman number", lhs.number);
	}
	return lhs;
}

Roman_int operator/(Roman_int lhs, const Roman_int rhs)
{
	lhs.number /= rhs.number;
	if (!Roman_int::is_valid(lhs.number))
	{
		error("Value is unknown in Roman number", lhs.number);
	}
	return lhs;
}

Roman_int operator%(Roman_int lhs, const Roman_int rhs)
{
	lhs.number %= rhs.number;
	if (!Roman_int::is_valid(lhs.number))
	{
		error("Value is unknown in Roman number", lhs.number);
	}
	return lhs;
}
