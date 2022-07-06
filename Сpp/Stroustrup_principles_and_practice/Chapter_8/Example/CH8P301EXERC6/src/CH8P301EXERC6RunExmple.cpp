/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 01/08/2022 14:46:34
	author														: Andrei-KS
*/

#include "CH8P301EXERC6RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH8P301EXERC6RunExmple();

namespace {
	/*
* Reverse function produce a new vector with the reversed sequence,
* leaving its original vector unchanged
* @param v - original vector
* @return new vector with the reversed sequence
*/
	vector<string> reverse_make_new_vector(const vector<string>& v)
	{
		vector<string> ret;
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
	void reverse_on_place(vector<string>& v)
	{
		size_t sizeV = v.size();
		size_t halfSizeV = sizeV / 2;
		for (size_t i = 0; i < halfSizeV; i++)
		{
			swap(v[sizeV - i - 1], v[i]);
		}
	}
}

int CH8P301EXERC6RunExmple::excute()
{
	vector<string> v = { "a", "ab", "abc", "b"};
	vector<string> rev = reverse_make_new_vector(v);
	reverse_on_place(v);
	return 0;
}