/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/17/2021 18:34:15
	author                                       : Andrei-KS
*/

#include "CH4P166TASK2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P166TASK2RunExmple();

namespace {
}

int CH4P166TASK2RunExmple::excute()
{
	cout << "Please, entry two int:";
	vector<int> nums;
	int temp = 0;
	int min = INT_MAX;
	int max = INT_MIN;
	while (cin >> temp)
	{
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
	return 0;
}