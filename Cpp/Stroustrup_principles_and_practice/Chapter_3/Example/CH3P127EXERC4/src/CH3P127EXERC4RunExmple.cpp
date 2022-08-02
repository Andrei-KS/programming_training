/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/17/2021 12:00:00
	author														: Andrei-KS
*/

#include "CH3P127EXERC4RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P127EXERC4RunExmple();

namespace {
}

int CH3P127EXERC4RunExmple::excute()
{
	int val1	= 0;
	int val2	= 0;
	cout << "Please, entry two int value:\n";
	cout << "First int: ";
	cin >> val1;
	cout << "Second int: ";
	cin >> val2;
	cout << "max(" << val1 << "," << val2 << ") == " << (val1 >= val2 ? val1 : val2) << "\n"
		<< val1 << " + " << val2 << " == " << val1 + val2 << "\n"
		<< val1 << " - " << val2 << " == " << val1 - val2 << "\n"
		<< val1 << " * " << val2 << " == " << val1 * val2 << "\n";
	if (val2 != 0)
	{
		cout << val1 << " / " << val2 << " == " << val1 / val2 << "\n";
	}

	return 0;
}