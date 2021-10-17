/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/17/2021 12:41:00
	author                                       : Andrei-KS
*/

#include "CH3P127EXERC6RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P127EXERC6RunExmple();

namespace {
}

int CH3P127EXERC6RunExmple::excute()
{
	int v1 = 0;
	int v2 = 0;
	int v3 = 0;
	int temp = 0;
	cout << "Please, entry three int:\n";
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