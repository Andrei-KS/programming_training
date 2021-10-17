/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/16/2021 12:53:40
	author                                       : Andrei-KS
*/

#include "CH3P125TASK7RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH3P125TASK7RunExmple();

namespace {
}

int CH3P125TASK7RunExmple::excute()
{
	cout << "Enter your name (and press 'Enter):\n";
	string name;
	cin >> name;
	cout << "Enter the recipient's name (and press 'Enter):\n";
	string first_name;
	cin >> first_name;

	cout << "Enter the recipient's age (and press 'Enter):\n";
	int age;
	cin >> age;
	if (age <= 0 || age >= 110)
	{
		simple_error("you are kidding!");
	}

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
		cout << "If you see " << friend_name << ", please ask him to call me.\n";
	}
	else if (friend_sex == 'f')
	{
		cout << "If you see " << friend_name << ", please ask her to call me.\n";
	}

	cout << "I heard you just celebrated your birthday and you are " << age << " years old.\n";

	if (age < 12)
	{
		cout << "Next year you will be " << age + 1 << " years old.\n";
	}
	else if (age == 17)
	{
		cout << "Next year you can vote.\n";
	}
	else if (age > 70)
	{
		cout << "I hope you don't miss at retirement.\n";
	}

	cout << "Sincerely yours\n\n\t" << name << "\n";
	return 0;
}