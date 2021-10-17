/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/17/2021 12:55:15
	author                                       : Andrei-KS
*/

#include "CH3P127EXERC7RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P127EXERC7RunExmple();

namespace {
}

int CH3P127EXERC7RunExmple::excute()
{
	string v1;
	string v2;
	string v3;
	string temp;
	cout << "Please, entry three words:\n";
	cout << "v1: ";
	cin >> v1;
	cout << "v2: ";
	cin >> v2;
	if (v1 > v2)
	{
		temp = v2;
		v2 = v1;
		v1 = temp;
	}
	cout << "v3: ";
	cin >> v3;
	if (v3 < v1)
	{
		temp = v3;
		v3 = v2;
		v2 = v1;
		v1 = temp;
	}
	else if (v3 < v2)
	{
		temp = v3;
		v3 = v2;
		v2 = temp;
	}
	cout << v1 << ", " << v2 << ", " << v3 << "\n";
	return 0;
}