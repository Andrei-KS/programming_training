/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/16/2021 11:06:23
	author                                       : Andrei-KS
*/

#include "CH3P124TASK1RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P124TASK1RunExmple();

namespace {
}

int CH3P124TASK1RunExmple::excute()
{
	cout << "Enter the recipient's name  (and press 'Enter):\n";
	string first_name;
	cin >> first_name;
	cout << "Dear " << first_name << ",\n";
	return 0;
}