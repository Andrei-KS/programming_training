/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/17/2021 15:35:34
	author														: Andrei-KS
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