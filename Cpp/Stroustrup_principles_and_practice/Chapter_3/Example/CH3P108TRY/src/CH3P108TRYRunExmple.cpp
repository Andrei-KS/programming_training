/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/15/2021 09:59:19
	author														: Andrei-KS
*/

#include "CH3P108TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P108TRYRunExmple();

namespace {
}

int CH3P108TRYRunExmple::excute()
{
	cout << "Please, enter the integer value\n";
	int n = 0;
	cin >> n;
	cout << "n == " << n + 1
		<< "\nn * 3 == " << n * 3
		<< "\nn+n == " << n + n
		<< "\nn/2 == " << n / 2
		<< "\nsqrt(n) == " << sqrt(n)
		<< "\nn/5*5 + n%5 == " << n
		<< "\n";
	return 0;
}