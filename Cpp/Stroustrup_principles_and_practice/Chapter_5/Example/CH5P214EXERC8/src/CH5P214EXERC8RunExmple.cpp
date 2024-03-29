/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/31/2021 00:47:14
	author														: Andrei-KS
*/

#include "CH5P214EXERC8RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH5P214EXERC8RunExmple();

namespace {
}

int CH5P214EXERC8RunExmple::excute()
{
	cout << "Entry number of summed values: ";
	int num = 0;
	cin >> num;
	cout << "Enter a few total numbers (| for the end of the entry): ";
	vector<int> values;
	int sum = 0;
	for (int temp = 0, i = 0; cin >> temp; ++i)
	{
		values.push_back(temp);
		if (i < num)
		{
			sum += temp;
		}
	}

	if (num > values.size())
	{
		error("number of summed values more than size of values vector");
	}

	cout << "The sum of the first " << num << " numbers (";
	for (int i = 0; i < num; ++i)
	{
		cout << values[i];
		if (i + 1 < num) cout << " ";
	}
	cout << ") is " << sum << "\n";
	return 0;
}