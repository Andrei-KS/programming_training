/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/24/2021 23:36:57
	author                                       : Andrei-KS
*/

#include "CH4P169EXERC4RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P169EXERC4RunExmple();

namespace {
}

int CH4P169EXERC4RunExmple::excute()
{
	cout << "Set a number from 1 to 100: ";
	constexpr int LEFTBOUND = 1;
	constexpr int RIGHTBOUND = 100;
	int num;
	cin >> num;
	if (num < LEFTBOUND || num > RIGHTBOUND)
	{
		cout << "Error: number is invalid\n";
		return 0;
	}

	int left = LEFTBOUND;
	int right = RIGHTBOUND;
	while (left + 1 < right)
	{
		int mid = (right - left) / 2 + left;
		cout << "Is number greater than " << mid << "? (y/n)\n";
		char answer;
		cin >> answer;
		switch (answer)
		{
		case 'y':
		{
			left = mid;
			break;
		}
		case 'n':
		{
			right = mid;
		}
		default:
			break;
		}
	}
	cout << "Is number equal " << left << "?\n";
	char answer;
	cin >> answer;
	int result = answer == 'y'? left : right;
	cout << "hidden number: " << result << "\n";
	return 0;
}