/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 08/01/2022 17:42:07
	author														: Andrei-KS
*/

#include "CH11P408EXERC16RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH11P408EXERC16RunExmple();

namespace {
	int search_in_vector(int num, const vector<pair<int, int>>& vect)
	{
		for (int index = 0; index < vect.size(); index++)
		{
			if (num == vect[index].first)
			{
				return index;
			}
		}
		return -1;
	}

	bool compare_pair_int_int(pair<int, int> left, pair<int, int> right)
	{
		return left < right;
	}
}

int CH11P408EXERC16RunExmple::excute()
{
	cout << "The program to read a file of whitespace-separated numbers and output them\n"
		<< " in order (lowest value first), one value per line. Write a value only once,\n"
		<< "and if it occurs more than once write the count of its occurrences on its line.\n"
		<< "Please enter file name: ";
	string file_name;
	cin >> file_name;
	ifstream file{ file_name };
	if (!file)
	{
		error("Can't open file ", file_name);
	}

	vector<pair<int,int>> numbers;
	for (int number; file >> number;)
	{
		int index_in_vector = search_in_vector(number, numbers);
		if (index_in_vector != -1)
		{
			numbers[index_in_vector].second++;
		}
		else
		{
			numbers.push_back({ number,1 });
		}
	}

	sort(numbers.begin(), numbers.end(), compare_pair_int_int);
	
	for (pair<int, int> number : numbers)
	{
		cout << number.first;
		if (number.second > 1)
		{
			cout << "\t" << number.second;
		}
		cout << "\n";
	}


	return 0;
}