/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/16/2021 11:20:54
	author														: Andrei-KS
*/

#include "CH3P124TASK3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P124TASK3RunExmple();

namespace {
}

int CH3P124TASK3RunExmple::excute()
{
	cout << "Enter the recipient's name (and press 'Enter):\n";
	string first_name;
	cin >> first_name;
	cout << "Enter another friend's name (and press 'Enter):\n";
	string friend_name;
	cin >> friend_name;
	cout << "Dear " << first_name << ",\n"
		<< "How are you?\nI'm fine. I miss you.\n"
		<< "How long have you met " << friend_name << "?\n";
	return 0;
}