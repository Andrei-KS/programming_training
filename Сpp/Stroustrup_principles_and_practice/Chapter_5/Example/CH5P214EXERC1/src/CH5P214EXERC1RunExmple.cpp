/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/30/2021 12:43:42
	author                                       : Andrei-KS
*/

#include "CH5P214EXERC1RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH5P214EXERC1RunExmple();

namespace {
	double ctok(double c)
	{
		double k = c + 273.15;
		return k;
	}
}

int CH5P214EXERC1RunExmple::excute()
{
	double c = 0;
	cin >> c;
	double k = ctok(c);
	cout << k << '\n';
	return 0;
}