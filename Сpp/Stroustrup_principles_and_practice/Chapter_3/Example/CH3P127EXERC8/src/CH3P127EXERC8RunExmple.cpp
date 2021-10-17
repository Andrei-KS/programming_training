/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/17/2021 13:02:39
	author                                       : Andrei-KS
*/

#include "CH3P127EXERC8RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P127EXERC8RunExmple();

namespace {
}

int CH3P127EXERC8RunExmple::excute()
{
	cout << "The program of int checking parity.\n"
		<< "Please, entry int: \n";
	int value;
	cin >> value;
	if (value % 2 == 0)
	{
		cout << value << " is even.\n";
	}
	else
	{
		cout << value << " is odd.\n";
	}
	return 0;
}