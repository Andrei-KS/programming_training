/*
	author														: Andrei-KS
*/

#ifndef __ROMAN_INT_H__
#define __ROMAN_INT_H__

#include "std_lib_facilities.h"

/*
* I 1
* V 5
* X 10
* L 50
* C 100
* D 500
* M 1000
* @author Andrei-KS
*/
class Roman_int {
public:
	//------------------------ Static section
	/* Check the correct writing of the Roman number.
	* @param roman_str - contane Roman number.
	* @return true if the Roman number is correctly written in string, otherwise false.
	*/
	static bool is_valid(const string& roman_str);
	/* Check the correct Roman value.
	* @param roman_value - contane Roman value.
	* @return true if the Roman value is correct, otherwise false.
	*/
	static bool is_valid(const int roman_value);

	//------------------------ Constructor section
	/**/
	Roman_int();
	/**/
	Roman_int(const int arab_number);
	/**/
	Roman_int(const Roman_int& other);
	/**/
	Roman_int(const string& roman_str);

	//------------------------ Operator section
	//---------------- I/O operators
	/**/
	friend istream& operator>>(istream& ist, Roman_int& roman_int);
	/**/
	friend ostream& operator<<(ostream& ost, const Roman_int& roman_int);
	//---------------- Comparison operators 
	/**/
	friend bool operator==(const Roman_int& lhs, const Roman_int& rhs);
	/**/
	friend bool operator!=(const Roman_int& lhs, const Roman_int& rhs);
	/**/
	friend bool operator< (const Roman_int& lhs, const Roman_int& rhs);
	/**/
	friend bool operator> (const Roman_int& lhs, const Roman_int& rhs);
	/**/
	friend bool operator<=(const Roman_int& lhs, const Roman_int& rhs);
	/**/
	friend bool operator>=(const Roman_int& lhs, const Roman_int& rhs);
	//---------------- Binary arithmetic operators
	/**/
	friend Roman_int operator+(Roman_int lhs, const Roman_int rhs);
	/**/
	friend Roman_int operator-(Roman_int lhs, const Roman_int rhs);
	/**/
	friend Roman_int operator*(Roman_int lhs, const Roman_int rhs);
	/**/
	friend Roman_int operator/(Roman_int lhs, const Roman_int rhs);
	/**/
	friend Roman_int operator%(Roman_int lhs, const Roman_int rhs);
	/**/
	friend Roman_int operator+=(Roman_int& lhs, const Roman_int rhs);
	/**/
	friend Roman_int operator-=(Roman_int& lhs, const Roman_int rhs);
	/**/
	friend Roman_int operator*=(Roman_int& lhs, const Roman_int rhs);
	/**/
	friend Roman_int operator/=(Roman_int& lhs, const Roman_int rhs);
	/**/
	friend Roman_int operator%=(Roman_int& lhs, const Roman_int rhs);


	 
	//------------------------ Other function section
	/*
	* @return int that was converted from the Roman number
	*/
	int as_int();

private:
	int number;
};

#endif // !__ROMAN_INT_H__