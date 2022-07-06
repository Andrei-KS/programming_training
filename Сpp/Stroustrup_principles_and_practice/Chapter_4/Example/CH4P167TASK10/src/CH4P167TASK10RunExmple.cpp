/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/19/2021 10:02:53
	author														: Andrei-KS
*/

#include "CH4P167TASK10RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P167TASK10RunExmple();

namespace {
}

int CH4P167TASK10RunExmple::excute()
{
	constexpr double accuracy = 1.0 / 100;
	constexpr double m_per_cm = 1.0 / 100.0;
	constexpr double cm_pre_in = 2.54 / 1;
	constexpr double in_per_ft = 12 / 1;

	cout << "Please, entry num and unit:";
	vector<double> nums;
	vector<double> valuesInM;

	vector<string> units;
	double temp_value = 0;
	string temp_unit = "";
	double sum = 0;
	while (cin >> temp_value >> temp_unit)
	{
		double result = 0;
		if (temp_unit == "cm" || temp_unit == "m"
			|| temp_unit == "in" || temp_unit == "ft")
		{
			switch (temp_unit[0])
			{
			case 'm':
			{
				result = temp_value;
				break;
			}
			case 'c':
			{
				result = temp_value * m_per_cm;
				break;
			}
			case 'i':
			{
				result = temp_value * cm_pre_in * m_per_cm;
				break;
			}
			case 'f':
			{
				result = temp_value * in_per_ft * cm_pre_in * m_per_cm;
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
			continue;
		}
		nums.push_back(temp_value);
		units.push_back(temp_unit);
		valuesInM.push_back(result);
		sum += result;
	}
	for (size_t i = 0; i < valuesInM.size(); ++i)
	{
		cout << valuesInM[i] << " m\n";
	}
	cout << "sum == " << sum << " m\n";

	return 0;
}