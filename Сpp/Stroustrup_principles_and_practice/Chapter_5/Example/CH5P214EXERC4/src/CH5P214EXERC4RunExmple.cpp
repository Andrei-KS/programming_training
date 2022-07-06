/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/30/2021 17:02:36
	author														: Andrei-KS
*/

#include "CH5P214EXERC4RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH5P214EXERC4RunExmple();

namespace {
	constexpr double ABSOLUT_TEMPERATURE_ZERO = -273.15; // [C]
	double ctok(double c)
	{
		if (c < ABSOLUT_TEMPERATURE_ZERO)
		{
			ostringstream os;
			os << "the temperature can not be less than " << ABSOLUT_TEMPERATURE_ZERO << "\n";
			error(os.str());
		}
		double k = c + 273.15;
		return k;
	}
}

int CH5P214EXERC4RunExmple::excute()
{
	cout << "Entry temperature in [C]: ";
	double c = 0;
	cin >> c;
	double k = ctok(c);
	cout << k << '\n';
	return 0;
}