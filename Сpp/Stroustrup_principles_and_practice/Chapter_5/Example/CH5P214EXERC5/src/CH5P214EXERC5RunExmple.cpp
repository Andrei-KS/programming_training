/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/30/2021 18:55:43
	author                                       : Andrei-KS
*/

#include "CH5P214EXERC5RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH5P214EXERC5RunExmple();

namespace {
	constexpr double ABSOLUT_TEMPERATURE_ZERO_IN_C = -273.15;	// [C]
	constexpr double ABSOLUT_TEMPERATURE_ZERO_IN_K = 0;			// [K]
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
}

int CH5P214EXERC5RunExmple::excute()
{
	cout << "Entry temperature in [K]: ";
	double temp_k = 0;
	cin >> temp_k;
	double temp_c = ktoc(temp_k);
	cout << temp_c << '\n';
	return 0;
}