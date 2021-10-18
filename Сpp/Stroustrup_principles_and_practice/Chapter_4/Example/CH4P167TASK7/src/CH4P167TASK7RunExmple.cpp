/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/18/2021 01:16:05
	author                                       : Andrei-KS
*/

#include "CH4P167TASK7RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P167TASK7RunExmple();

namespace {
}

int CH4P167TASK7RunExmple::excute()
{
	constexpr double accuracy	= 1.0 / 100;
	constexpr double cm_per_m	= 100 / 1.0;
	constexpr double cm_pre_in	= 2.54 / 1;
	constexpr double in_per_ft	= 12 / 1;

	cout << "Please, entry num and unit:";
	vector<double> nums;
	vector<string> units;
	double temp_value	= 0;
	string temp_unit	= "";
	while (cin >> temp_value >> temp_unit)
	{
		if (temp_unit == "cm" || temp_unit == "m" 
			|| temp_unit == "in" || temp_unit == "ft")
		{
			nums.push_back(temp_value);
			units.push_back(temp_unit);
		}
	}
	int i = 0;
	while (i < nums.size() && i < units.size())
	{
		cout << nums[i] << " " << units[i] << "\n";
		++i;
	}
	return 0;
}