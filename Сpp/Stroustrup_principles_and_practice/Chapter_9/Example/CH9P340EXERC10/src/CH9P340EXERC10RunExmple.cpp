/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 01/21/2022 10:23:49
	author                                       : Andrei-KS
*/

#include "CH9P340EXERC10RunExmple.h"
#include "std_lib_facilities.h"
#include "Chrono.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH9P340EXERC10RunExmple();

namespace {
}

int CH9P340EXERC10RunExmple::excute()
{
	const int width = 5;
	vector<int> years = {
		1,		//False
		400,	//True
		100,	//False
		200,	//False
		204,	//True
		2000,	//True
		2001,	//False
		2002,	//False
		2004,	//True
		2005,	//False
	};
	for (int year : years)
	{
		cout << "Chrono::leapyear(" << std::setw(width) << std::left << year << ") : " << std::boolalpha << Chrono::leapyear(year) << '\n';
	}
	return 0;
}