/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/17/2021 15:49:34
	author                                       : Andrei-KS
*/

#include "CH4P157TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P157TRYRunExmple();

namespace {
	int square(int x)
	{
		int result = 0;
		for (int i = 0; i < x; ++i)
		{
			result += x;
		}
		return result;
	}
}

int CH4P157TRYRunExmple::excute()
{
	cout << "Please, entry value: ";
	int val;
	cin >> val;
	cout << "square( " << val << " ) == " << square(val) << "\n";
	return 0;
}