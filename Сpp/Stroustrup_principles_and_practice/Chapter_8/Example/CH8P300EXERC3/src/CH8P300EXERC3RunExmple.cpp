/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 12/22/2021 09:06:27
	author                                       : Andrei-KS
*/

#include "CH8P300EXERC3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH8P300EXERC3RunExmple();

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

	/*
	* A function which will add fibonacci sequence to end of given vector, 
	* where fibonacci sequence is given by F[n]=F[n-1]+F[n-2]
	* @param x - zeroth element of fibonacci sequence
	* @param y - first element of fibonacci sequence
	* @param v - vector where fibonacci sequence will added
	* @param n - number elements in fibonacci sequence
	*/
	void fibonacci(int x, int y, vector<int>& v, int n)
	{
		if (n > 0)
		{
			v.push_back(x);
		}
		if (n > 1)
		{
			v.push_back(y);
		}
		for(int i = 2; i < n; i++)
		{
			v.push_back(v[i - 1] + v[i - 2]);
		}
	}
}

int CH8P300EXERC3RunExmple::excute()
{
	vector<int> v;
	fibonacci(1, 1, v, 7);
	return 0;
}