/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/24/2021 21:20:19
	author                                       : Andrei-KS
*/

#include "CH4P169EXERC2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P169EXERC2RunExmple();

namespace {
	double find_median(vector<double> array)
	{
		sort(array);
		size_t size = array.size();
		if (size % 2 == 1)
		{
			return array[size / 2];
		}
		else
		{
			return 0.5 * (array[size / 2 - 1] + array[size / 2]);
		}
	}

	void test(const vector<double>& array, const pair<double, double> answer)
	{
		cout << "Test: { ";
		for (int i = 0; i < array.size(); ++i)
		{
			cout << array[i] << ", ";
		}
		cout << "}\n";
		cout << "answer\t: " << answer.first << "-" << answer.second << "\n";

		double median = find_median(array);
		cout << "median\t: " << median << "\n";
		if (median < answer.first || median > answer.second)
		{
			cout << "---Test FAIL---\n\n";
		}
		else
		{
			cout << "---Test ACCEPT---\n\n";
		}
	}
}

int CH4P169EXERC2RunExmple::excute()
{
	test({ 1, 2, 3, }, { 2, 2, });
	test({ 1, 1, 2, 3, 3, }, { 2, 2, });
	test({ 1, 2, 3, 3, }, { 2, 3, });
	test({ 1, 2, 2, 2, }, { 1, 2, });
	test({ 1, 1, 1, 2, }, { 1, 2, });
	test({ 1, 2, 2, 3, 3, }, { 2, 3, });
	test({ 1, 2, 3, 4, }, { 2, 3, });
	test({ 1, 3, 3, 2, }, { 2, 3, });

	return 0;
}