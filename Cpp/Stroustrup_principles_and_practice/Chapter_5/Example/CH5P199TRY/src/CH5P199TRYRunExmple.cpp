/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/28/2021 23:55:28
	author														: Andrei-KS
*/

#include "CH5P199TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH5P199TRYRunExmple();

namespace {
	void funtion_sum_high_low(const vector<double> temps)
	{
		constexpr double min_temp = -459.67;	// [F], this temperature value equal 0 K
		constexpr double max_temp = 1.40e+32;	// [F], this temperature value equal the Planck temperature
		double sum = 0;
		double high_temp = min_temp;
		double low_temp = max_temp;
		for (double x : temps)
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

int CH5P199TRYRunExmple::excute()
{
	funtion_sum_high_low({ 1.0, 2.0, 3.0, });
	funtion_sum_high_low({ -1.0, -2.0, -3.0, });
	funtion_sum_high_low({ 1.1, 1.1, 1.1, });
	return 0;
}