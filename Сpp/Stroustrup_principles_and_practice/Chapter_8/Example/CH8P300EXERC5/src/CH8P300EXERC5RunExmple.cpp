/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 01/08/2022 14:29:24
	author                                       : Andrei-KS
*/

#include "CH8P300EXERC5RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH8P300EXERC5RunExmple();

namespace {
	/*
	* Reverse function produce a new vector with the reversed sequence,
	* leaving its original vector unchanged
	* @param v - original vector
	* @return new vector with the reversed sequence
	*/
	vector<int> reverse_make_new_vector(const vector<int>& v)
	{
		vector<int> ret;
		size_t sizeV = v.size();
		for (size_t i = 0; i < sizeV; i++)
		{
			ret.push_back(v[sizeV - i - 1]);
		}
		return ret;
	}

	/*
	* Reverse function reverse the elements of its vector without using any other vectors
	* @param v - original vector
	*/
	void reverse_on_place(vector<int>& v)
	{
		size_t sizeV = v.size();
		size_t halfSizeV = sizeV / 2;
		for (size_t i = 0; i < halfSizeV; i++)
		{
			swap(v[sizeV - i - 1], v[i]);
		}
	}
}

int CH8P300EXERC5RunExmple::excute()
{
	vector<int> v = { 1,2,3,4 };
	vector<int> rev = reverse_make_new_vector(v);
	reverse_on_place(v);
	return 0;
}