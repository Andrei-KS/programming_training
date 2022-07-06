/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/30/2021 12:47:21
	author														: Andrei-KS
*/

#include "CH5P214EXERC2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH5P214EXERC2RunExmple();

namespace {
	double ctok(double c)
	{
		double k = c + 273.15;
		return k;
	}
}

int CH5P214EXERC2RunExmple::excute()
{
	double c = 0;
	cin >> c;
	double k = ctok(c);
	cout << k << '\n';
	return 0;
}