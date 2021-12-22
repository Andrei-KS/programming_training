/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 12/22/2021 08:54:58
	author                                       : Andrei-KS
*/

#include "CH8P300EXERC2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH8P300EXERC2RunExmple();

namespace {
	/*
	* A function print that prints a vector of ints to cout. 
	* @param str - for “labeling” the output.
	* @param v - contain sequence of ints for cout.
	*/
	void print(string& str, const vector<int>& v)
	{
		for (const int i : v)
		{
			str = str + to_string(i) + ' ';
		}
	}
}

int CH8P300EXERC2RunExmple::excute()
{
	string str;
	vector<int> v{ 1,2,3,4,5,6,7,8 };
	print(str, v);
	cout << str;
	return 0;
}