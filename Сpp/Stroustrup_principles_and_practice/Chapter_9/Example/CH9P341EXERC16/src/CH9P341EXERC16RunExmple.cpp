/*
	This file is created from a mocks that is in : C:/GitHub/programming_training/Сpp/Stroustrup_principles_and_practice/include
	date generate                                : 02/07/2022 09:37:51
	author                                       : Andrei-KS
*/

#include "CH9P341EXERC16RunExmple.h"
#include "std_lib_facilities.h"
#include "Money.h"

RunCommandOfExample* RunCommandOfExample::runCommandOfExample = new CH9P341EXERC16RunExmple();

namespace {
}

int CH9P341EXERC16RunExmple::excute()
{
	MyLib::Money money(10001, MyLib::Currency::USD);
	cout << money << "\n";
	MyLib::Money money1(10000, MyLib::Currency::USD);
	cout << money1 << "\n";
	cin >> money;
	cout << money;
	return 0;
}