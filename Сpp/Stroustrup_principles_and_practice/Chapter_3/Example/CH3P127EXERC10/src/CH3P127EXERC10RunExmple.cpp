/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/17/2021 13:13:51
	author                                       : Andrei-KS
*/

#include "CH3P127EXERC10RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P127EXERC10RunExmple();

namespace {
}

int CH3P127EXERC10RunExmple::excute()
{
	char operation;
	double v1;
	double v2;
	cout << "Please, entry operation and two value:\n";
	cin >> operation >> v1 >> v2;
	if (operation == '+') cout << v1 + v2;
	if (operation == '-') cout << v1 - v2;
	if (operation == '*') cout << v1 * v2;
	if (operation == '/')
	{
		if(v2 != 0)
		{
			cout << v1 + v2;
		}
		else
		{
			cout << "error: v2 is invalid value";
		}
	}
	return 0;
}