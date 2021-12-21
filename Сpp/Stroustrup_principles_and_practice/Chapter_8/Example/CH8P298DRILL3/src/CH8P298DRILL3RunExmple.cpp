/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 12/21/2021 10:17:38
	author                                       : Andrei-KS
*/

#include "CH8P298DRILL3RunExmple.h"
#include "std_lib_facilities.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH8P298DRILL3RunExmple();

namespace X
{
	int var;
	void print()
	{
		cout << var << '\n';
	}
}

namespace Y
{
	int var;
	void print()
	{
		cout << var << '\n';
	}
}

namespace Z
{
	int var;
	void print()
	{
		cout << var << '\n';
	}
}

int CH8P298DRILL3RunExmple::excute()
{
	X::var = 7;
	X::print();				// print X's var
	using namespace Y;
	var = 9;
	print();					// print Y's var
	{
		using Z::var;
		using Z::print;
		var = 11;
		print();				// print Z's var
	}

	X::print();
	Y::print();
	Z::print();

	return 0;
}