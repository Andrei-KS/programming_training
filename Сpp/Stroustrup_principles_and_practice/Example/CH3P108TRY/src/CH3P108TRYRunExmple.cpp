/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/15/2021 09:59:19
	author                                       : Andrei-KS
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
		<< "\n";
	return 0;
}