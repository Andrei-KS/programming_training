/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/30/2021 21:16:37
	author														: Andrei-KS
*/

#include "CH5P214EXERC6RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH5P214EXERC6RunExmple();

namespace {
	constexpr double ABSOLUT_TEMPERATURE_ZERO_IN_C = -273.15;	// [C]
	constexpr double ABSOLUT_TEMPERATURE_ZERO_IN_K = 0.0;			// [K]
	constexpr double ABSOLUT_TEMPERATURE_ZERO_IN_F = -459.67;	// [F]
	double ctok(double c)
	{
		if (c < ABSOLUT_TEMPERATURE_ZERO_IN_C)
		{
			ostringstream os;
			os << "the temperature can not be less than " << ABSOLUT_TEMPERATURE_ZERO_IN_C << "\n";
			error(os.str());
		}
		double k = c + ABSOLUT_TEMPERATURE_ZERO_IN_C;
		return k;
	}
	double ktoc(double k)
	{
		if (k < ABSOLUT_TEMPERATURE_ZERO_IN_K)
		{
			ostringstream os;
			os << "the temperature can not be less than " << ABSOLUT_TEMPERATURE_ZERO_IN_K << "\n";
			error(os.str());
		}
		return k + ABSOLUT_TEMPERATURE_ZERO_IN_C;
	}
	double ftoc(double f)
	{
		if (f < ABSOLUT_TEMPERATURE_ZERO_IN_F)
		{
			ostringstream os;
			os << "the temperature can not be less than " << ABSOLUT_TEMPERATURE_ZERO_IN_F << "\n";
			error(os.str());
		}
		return (f - 32.0) * 5.0 / 9.0;
	}
	double ctof(double c)
	{
		if (c < ABSOLUT_TEMPERATURE_ZERO_IN_C)
		{
			ostringstream os;
			os << "the temperature can not be less than " << ABSOLUT_TEMPERATURE_ZERO_IN_C << "\n";
			error(os.str());
		}
		return c *9.0/5.0 + 32;
	}
}

int CH5P214EXERC6RunExmple::excute()
{
	cout << "Entry temperature in [F]: ";
	double temp_f = 0;
	cin >> temp_f;
	double temp_c = ftoc(temp_f);
	cout << temp_c << '\n';
	cout << ctof(temp_c) << "\n";
	return 0;
}