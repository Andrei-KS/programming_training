/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/17/2021 18:27:48
	author														: Andrei-KS
*/

#include "CH4P166TASK1RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P166TASK1RunExmple();

namespace {
}

int CH4P166TASK1RunExmple::excute()
{
	cout << "Please, entry two int:";
	vector<int> nums;
	int temp = 0;
	while (cin >> temp)
	{
		nums.push_back(temp);
		if(nums.size() > 1) break;
	}
	int i = 0;
	while (i < nums.size())
	{
		cout << nums[i] << "\n";
		++i;
	}
	return 0;
}