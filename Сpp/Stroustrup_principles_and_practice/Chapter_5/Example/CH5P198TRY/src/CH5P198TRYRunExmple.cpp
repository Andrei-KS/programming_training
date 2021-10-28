/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/28/2021 23:43:21
	author                                       : Andrei-KS
*/

#include "CH5P198TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH5P198TRYRunExmple();

namespace {
	void funtion_sum_high_low(const vector<double> temps)
	{
		double sum			= 0;
		double high_temp	= 0;
		double low_temp	= 0;
		for (int x : temps)
		{
			if (x > high_temp) high_temp = x;
			if (x < low_temp) low_temp = x;
			sum += x;
		}

		cout << "Max\t: " << high_temp << "\n";
		cout << "Min\t: " << low_temp << '\n';
		cout << "Sum\t: " << sum << "\n";
	}
}

int CH5P198TRYRunExmple::excute()
{
	funtion_sum_high_low({ 1.0, 2.0, 3.0, });			// get invalid low
	funtion_sum_high_low({ -1.0, -2.0, -3.0, });		// get invalid high
	funtion_sum_high_low({ 1.1, 1.1, 1.1, });			// get invalid sum
	return 0;
}