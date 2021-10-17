/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/17/2021 15:35:34
	author                                       : Andrei-KS
*/

#include "CH4P154TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P154TRYRunExmple();

namespace {
}

int CH4P154TRYRunExmple::excute()
{
	for (char i = 'A'; i <= 'Z'; ++i)
	{
		cout << i << "\t" << int(i) << "\n";
	}
	for (char i = 'a'; i <= 'z'; ++i)
	{
		cout << i << "\t" << int(i) << "\n";
	}
	return 0;
}