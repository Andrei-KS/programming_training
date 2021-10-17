/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/17/2021 15:26:29
	author                                       : Andrei-KS
*/

#include "CH4P151TRYRunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P151TRYRunExmple();

namespace {
}

int CH4P151TRYRunExmple::excute()
{
	constexpr char end_symbol = 'z';
	char i = 'a';
	while ( i <= end_symbol)
	{
		cout << i << "\t" << int(i) << "\n";
		++i;
	}
	return 0;
}