/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 10/25/2021 21:39:09
	author                                       : Andrei-KS
*/

#include "CH4P169EXERC5RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH4P169EXERC5RunExmple();

namespace {
}

int CH4P169EXERC5RunExmple::excute()
{
	cout << "Enter operator (+,-,/,*) and two value:\n";
	char oper = '\0';
	double val1 = 0;
	double val2 = 0;
	cin >> oper >> val1 >> val2;
	switch (oper)
	{
	case '+':
	{
		cout << "Sum " << val1 << " and " << val2
			<< " equal " << val1 + val2 << "\n";
		break;
	}
	case '-':
	{
		cout << "Diff " << val1 << " and " << val2
			<< " equal " << val1 - val2 << "\n";
		break;
	}
	case '/':
	{
		if (val2 == 0)
		{
			cout << "val2 is invalid\n";
			break;
		}
		cout << "Div " << val1 << " by " << val2
			<< " equal " << val1 / val2 << "\n";
		break;
	}
	case '*':
	{
		cout << "Mult " << val1 << " and " << val2
			<< " equal " << val1 * val2 << "\n";
		break;
	}

	default:
		cout << "operator is invalid\n";
		break;
	}
	return 0;
}