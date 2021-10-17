/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/18/2021 01:12:08
	author                                       : Andrei-KS
*/

#include "CH4P166TASK6RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P166TASK6RunExmple();

namespace {
}

int CH4P166TASK6RunExmple::excute()
{
	constexpr double accuracy = 1.0 / 100;
	cout << "Please, entry two doubles:";
	vector<double> nums;
	double temp = 0;
	double min = std::numeric_limits<double>::max();
	double max = std::numeric_limits<double>::min();
	double prevNum = 0;
	while (cin >> temp)
	{
		nums.push_back(temp);
		if (temp > max) max = temp;
		if (temp < min) min = temp;
	}
	int i = 0;
	while (i < nums.size())
	{
		cout << nums[i] << "\n";
		++i;
	}
	cout << "Max == " << max << "\n"
		<< "Min == " << min << "\n";
	return 0;
}