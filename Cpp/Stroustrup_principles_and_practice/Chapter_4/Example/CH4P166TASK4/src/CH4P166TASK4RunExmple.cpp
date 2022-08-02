/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/18/2021 00:34:43
	author														: Andrei-KS
*/

#include "CH4P166TASK4RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P166TASK4RunExmple();

namespace {
}

int CH4P166TASK4RunExmple::excute()
{
	cout << "Please, entry two doubles:";
	vector<double> nums;
	double temp = 0;
	double min = std::numeric_limits<double>::max();
	double max = std::numeric_limits<double>::min();
	bool isNumbersEqual = true;
	double prevNum = 0;
	while (cin >> temp)
	{
		if (nums.size() > 0)
		{
			if (prevNum != temp) isNumbersEqual = false;
		}
		else
		{
			prevNum = temp;
		}
		nums.push_back(temp);
		if (temp > max) max = temp;
		if (temp < min) min = temp;
		if (nums.size() > 1) break;
	}
	int i = 0;
	while (i < nums.size())
	{
		cout << nums[i] << "\n";
		++i;
	}
	cout << "Max == " << max << "\n"
		<< "Min == " << min << "\n";
	if (isNumbersEqual) cout << "Numbers are equal\n";
	return 0;
}