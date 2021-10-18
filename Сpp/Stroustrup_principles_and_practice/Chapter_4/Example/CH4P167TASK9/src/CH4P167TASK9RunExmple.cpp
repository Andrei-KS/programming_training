/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/18/2021 10:14:30
	author                                       : Andrei-KS
*/

#include "CH4P167TASK9RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P167TASK9RunExmple();

namespace {
}

int CH4P167TASK9RunExmple::excute()
{
	constexpr double accuracy = 1.0 / 100;
	constexpr double m_per_cm = 1.0 / 100.0;
	constexpr double cm_pre_in = 2.54 / 1;
	constexpr double in_per_ft = 12 / 1;

	cout << "Please, entry num and unit:";
	vector<double> nums;
	vector<string> units;
	double temp_value = 0;
	string temp_unit = "";
	double sum = 0;
	while (cin >> temp_value >> temp_unit)
	{
		if (temp_unit == "cm" || temp_unit == "m"
			|| temp_unit == "in" || temp_unit == "ft")
		{
			nums.push_back(temp_value);
			units.push_back(temp_unit);
			switch (temp_unit[0])
			{
			case 'm':
			{
				sum += temp_value;
				break;
			}
			case 'c':
			{
				sum += temp_value * m_per_cm;
				break;
			}
			case 'i':
			{
				sum += temp_value  * cm_pre_in * m_per_cm;
				break;
			}
			case 'f':
			{
				sum += temp_value * in_per_ft * cm_pre_in * m_per_cm;
				break;
			}
			default:
			{}
			}
		}
		else
		{
			cout << "Incorrect unit entered: "
				<< temp_value << " " << temp_unit << "\n";
		}
	}
	int i = 0;
	while (i < nums.size() && i < units.size())
	{
		cout << nums[i] << " " << units[i] << "\n";
		++i;
	}
	cout << "sum == " << sum << " m\n";
	return 0;
}