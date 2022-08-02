/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/16/2021 11:15:40
	author														: Andrei-KS
*/

#include "CH3P124TASK2RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P124TASK2RunExmple();

namespace {
}

int CH3P124TASK2RunExmple::excute()
{
	cout << "Enter the recipient's name  (and press 'Enter):\n";
	string first_name;
	cin >> first_name;
	cout << "Dear " << first_name << ",\n"
		<< "How are you?\nI'm fine. I miss you.\n";
	return 0;
}