/*
	This file is generated from a layout that is in : {PROJECT_SOURCE_DIR}/include
	date generate												: 10/16/2021 11:44:37
	author														: Andrei-KS
*/

#include "CH3P124TASK4RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P124TASK4RunExmple();

namespace {
}

int CH3P124TASK4RunExmple::excute()
{
	cout << "Enter the recipient's name (and press 'Enter):\n";
	string first_name;
	cin >> first_name;
	cout << "Enter another friend's name (and press 'Enter):\n";
	string friend_name;
	cin >> friend_name;
	cout << "Enter m/f corresponding of friends sex (m - male, f - female):\n";
	char friend_sex = ' ';
	cin >> friend_sex;
	cout << "Dear " << first_name << ",\n"
		<< "How are you?\nI'm fine. I miss you.\n"
		<< "How long have you met " << friend_name << "?\n";
	if (friend_sex == 'm')
	{
		cout << "If you see " << friend_name  << ", please ask him to call me.\n";
	}
	else if (friend_sex == 'f')
	{
		cout << "If you see " << friend_name << ", please ask her to call me.\n";
	}
	return 0;
}